//
//  main.cpp
//  9376_탈옥
//
//  Created by Kim Seong Jin on 04/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define DOOR '#'
#define WALL '*'
#define PASS '.'
#define PERSON '$'

using namespace std;
//udrl
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, -1, 1};

typedef pair<int, int> pos;
typedef struct _PERSON{
    pos p;
    int idx;
    _PERSON(int _idx, pos _p){
        p = _p;
        idx = _idx;
    }
}person;

vector<vector<char>> map;
vector<vector<int>> path[4];
vector<int> exits;
vector<int> broken[4];
pos persons[2];
int n, m;

bool isRange(int y, int x){
    return 0<=y && y < n && 0 <= x && x < m;
}

void print(int idx){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cout<<path[idx][y][x]<<" ";
        }
        cout<<endl;
    }
}

void exitP2(){
    int sx, sy, nx, ny;
    vector<vector<int>> p;
    queue<pos> q;
    q.push(persons[1]);
    
    while(!q.empty()){
        pos current = q.front();
        sy = current.first;
        sx = current.second;
        
    }
    
    
}

void exitP1(){
    int sx, sy, nx, ny;
    queue<person> q;
    
    int idx = 1;
    sy = persons[0].first;
    sx = persons[0].second;
    
    for(int i = 0 ; i < 4 ; i++){
        ny = sy + dy[i];
        nx = sx + dx[i];
        if(isRange(ny, nx)){
            if(map[ny][nx] == DOOR ||  map[ny][nx] == PERSON){
                path[idx][sy][sx] = 1;
                path[idx][ny][nx] = 2;
                q.push(person(idx,pos(ny, nx)));
                idx++;
            }else if(map[ny][nx] == PASS){
                path[0][sy][sx] = 1;
                path[0][ny][nx] = 2;
                q.push(person(0,pos(ny, nx)));
            }
        }
    }
        
    
    while(!q.empty()){
        person current = q.front();
        q.pop();
        idx = current.idx;
        sy = current.p.first;
        sx = current.p.second;
        if(sy==0 || sy==n || sx==0 || sx==m){
            broken[idx] = path[sy][sx];
            exits.push_back(idx);
        }
        for(int i = 0 ; i < 4 ; i++){
            ny = sy + dy[i];
            nx = sx + dx[i];
            if(isRange(ny, nx) && path[idx][ny][nx] == 0){
                //(map[ny][nx] == DOOR || map[ny][nx] == PASS)
                if(map[ny][nx] == DOOR){
                    path[idx][ny][nx] = path[idx][sy][sx]+1;
                    q.push(person(idx, pos(ny, nx)));
                }else if(map[ny][nx] == PASS){
                    path[idx][ny][nx] = path[idx][sy][sx];
                    q.push(person(idx, pos(ny, nx)));
                }
            }
        }
    }
}


void build(){
    int idx=0;
    map = vector<vector<char>>(n, vector<char>(m, '.'));
    for(int i = 0 ; i <  4 ; i++){
        path[i] = vector<vector<int>>(n, vector<int>(m, 0));
    }
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cin>>map[y][x];
            if(map[y][x] == PERSON){
                persons[idx++] = pos(y,x);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    exitP1();
    
    for(int e : exits){
        print(e);
        cout<<endl;
    }
    
    return 0;
}

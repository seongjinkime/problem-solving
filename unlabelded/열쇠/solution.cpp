//
//  main.cpp
//  9328_열쇠
//
//  Created by Kim Seong Jin on 05/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#define MAX 101
#define EMPTY '.'
#define WALL '*'
#define DOCU '$'

using namespace std;
typedef pair<int, int> pos;
int h, w;
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, -1, 1};
vector<vector<char>>map;
set<int> keys;
bool retry;
int cnt;

bool inRange(int y, int x){
    return 0<=y && y < h && 0<=x && x<w;
}

bool hasKey(char ch){
    int k = ch - 'A';
    return keys.count(k) > 0;
}

void updateToEmpty(int sy, int sx, int ny, int nx, vector<vector<int>>& visited, queue<pos>& q){
    map[ny][nx] = EMPTY;
    visited[ny][nx] = visited[sy][sx]+1;
    q.push(pos(ny, nx));
}

void bfs(){
    int sy,sx,ny,nx;
    char ch;
    vector<vector<int>> visited = vector<vector<int>>(h, vector<int>(w, -1));
    queue<pos> q;
    q.push(pos(0,0));
    visited[0][0] = true;
    while(!q.empty()){
        pos here = q.front();
        sy = here.first;
        sx = here.second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            ny = sy + dy[i];
            nx = sx + dx[i];
            if(!inRange(ny, nx))
                continue;
            ch = map[ny][nx];
            if(ch == WALL)
                continue;
            
            if(ch == EMPTY && visited[ny][nx] == -1){
                visited[ny][nx] = visited[sy][sx];
                q.push(pos(ny, nx));
            }
            if(isupper(ch) && hasKey(ch)){
                retry = true;
                updateToEmpty(sy, sx, ny, nx, visited, q);
            }
            if('a' <= ch && ch <= 'z'){
                retry = true;
                keys.insert(ch-'a');
                updateToEmpty(sy, sx, ny, nx, visited, q);
            }
            if(ch == DOCU){
                retry = true;
                cnt += 1;
                updateToEmpty(sy, sx, ny, nx, visited, q);
            }
        }
    }
    
}

void print(){
    for(int y = 0 ; y < h ; y++){
        for(int x = 0 ; x < w ; x++){
            cout<<map[y][x];
        }
        cout<<endl;
    }
    cout<<endl;
    
}
void build(){
    string k;
    keys = set<int>();
    
    cin>>h>>w;
    
    w+=2;
    h+=2;
    map = vector<vector<char>>(h, vector<char>(w));
    
    for(int y = 0 ; y < h ; y++){
        
        for(int x = 0 ; x < w ; x++){
            if(y == 0 || y == h-1 || x == 0 || x == w-1){
                map[y][x] = EMPTY;
                continue;
            }
            cin>>map[y][x];
        }
    }
    cin>>k;
    for(char ch : k){
        if(ch!='0'){
            keys.insert(ch-'a');
        }
            
    }
}

void solve(){
    build();
    retry = true;
    cnt = 0;
    while(retry){
        retry =false;
        bfs();
    }
    cout<<cnt<<endl;
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        
        solve();
        
    }
    
    return 0;
}

//
//  main.cpp
//  4991_로봇청소기
//
//  Created by Kim Seong Jin on 06/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include<stdio.h>
#include <string.h>
#include <queue>
#define INF 987654321
#define MAX 21
#define CLEAN '.'
#define DIRTY '*'
#define FURNITURE 'x'
#define ROBOT 'o'

using namespace std;

typedef struct _ROBOT{
    int y, x;
    int id;
    _ROBOT(int _y, int _x, int _id){
        y  = _y;
        x  = _x;
        id = _id;
    }
}robot;


bool complete[11];
vector<pair<int, int>> tasks;
char map[MAX][MAX];
int visited [11][MAX][MAX];
int dy[4] {-1, 1, 0, 0};
int dx[4] { 0, 0, -1, 1};
int ry, rx; //robot y, robot x
int w, h;
int total;

bool inRange(int y, int x){
    return 0<=y && y < h && 0<=x && x<w;
}

int bfs(){
    int dist = INF;
    memset(visited, -1, sizeof(visited));
    int sy, sx, ny, nx;
    int id;
    queue<robot> q;
    for(id = 0 ; id < tasks.size() ; id++){
        if(!complete[id]){
            visited[id][ry][rx] = 0;
            q.push(robot(ry, rx, id));
        }
    }
    while(!q.empty()){
        robot current = q.front();
        sy = current.y;
        sx = current.x;
        id = current.id;
        q.pop();
        if(sy == tasks[id].first && sx == tasks[id].second){
            if(dist > visited[id][sy][sx]){
                complete[id] = true;
                map[sy][sx] = CLEAN;
                ry = sy;
                rx = sx;
                dist = visited[id][sy][sx];
            }
        }
        
        for(int i = 0 ; i < 4 ; i++){
            ny = sy + dy[i];
            nx = sx + dx[i];
            if(inRange(ny, nx) && visited[id][ny][nx] == -1){
                if(map[ny][nx] == FURNITURE)
                    continue;
                visited[id][ny][nx] = visited[id][sy][sx] + 1;
                q.push(robot(ny, nx, id));
            }
        }
        
    }
    if(dist == INF){
        return -1;
    }else{
        return dist;
    }
    
 
    
}

void build(){
    char ch;
    tasks.clear();
    memset(complete, false, sizeof(complete));
    
    
    for(int y = 0 ; y < h ; y++){
        for(int x = 0 ; x < w ; x++){
            cin>>ch;
            if(ch == ROBOT){
                ry = y;
                rx = x;
            }else if (ch == DIRTY){
                tasks.push_back(make_pair(y, x));
            }
            map[y][x] = ch;
        }
    }
}

void solve(){
    
    build();
    int cnt = 0;
    int dist;
    total = 0;
    while(cnt<tasks.size()){
        map[ry][rx] = CLEAN;
        dist = bfs();
        if(dist == -1){
            cout<<-1<<endl;
            return;
        }else{
            total += dist;
        }
        cnt++;
    }
    cout<<total<<endl;
}

int main(int argc, const char * argv[]) {
    while (true) {
        cin>>w>>h;
        if(w==0 & h == 0)
            break;
        solve();
    }
    
    return 0;
}

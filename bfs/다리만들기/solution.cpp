//
//  main.cpp
//  2146_다리만들기
//
//  Created by Kim Seong Jin on 21/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define land -1
#define sea -2
#define MAX 101

using namespace std;
//udrl
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, -1, 1};

typedef pair<int, int> pos;


int map[MAX][MAX];
int n;

bool inRange(int y, int x){
    return y>=0 && y < n && x>=0 && x < n;
}

void setAddress(int y, int x, int address){
    map[y][x] = address;
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(inRange(ny, nx)){
            if(map[ny][nx] == land){
                setAddress(ny, nx, address);
            }
        }
    }
}

void build(){
    int num;
    int address = 1;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cin>>num;
            map[y][x] = num==1 ? land : sea;
        }
    }
    
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            if(map[y][x] == land){
                setAddress(y, x, address);
                address++;
            }
        }
    }
}

int bridge(int y, int x, int num){
    int sy, sx, ny, nx;
    
    vector<vector<int>> visit = vector<vector<int>>(n, vector<int>(n, 0));
    queue<pos> q;
    q.push(pos(y, x));
    visit[y][x] = 0;
    
    while(!q.empty()){
        pos here = q.front();
        sy = here.first;
        sx = here.second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            ny = sy + dy[i];
            nx = sx + dx[i];
            if(inRange(ny, nx)){
                if(map[ny][nx] != sea && map[ny][nx] != num){
                    return visit[sy][sx];
                }
                if(map[ny][nx] == sea && visit[ny][nx] == 0){
                    visit[ny][nx] = visit[sy][sx] + 1;
                    q.push(pos(ny, nx));
                }
            }
        }
        
    }
    return -1;
    
}

void solve(){
    int ret = 987654321;
    int len;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            if(map[y][x]!=sea){
                len = bridge(y, x, map[y][x]);
                if(len!=-1)
                    ret = min(ret, len);
            }
        }
    }
    cout<<ret<<endl;
}


int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    solve();
    return 0;
}

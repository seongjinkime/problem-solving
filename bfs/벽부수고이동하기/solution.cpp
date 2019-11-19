//
//  main.cpp
//  2206_벽부수고이동하기
//
//  Created by Kim Seong Jin on 19/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 1001

using namespace std;
vector<vector<int>> map;
typedef pair<int, int> pos;

int n, m;
//udrl
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, 1, -1};




int bfs(int y, int x){
    int sy, sx, ny, nx;
    queue<pos> q;
    q.push(pos(y, x));
    map[y][x] = 1;
    while(!q.empty()){
        pos here = q.front();
        q.pop();
        
        sy = here.first;
        sx = here.second;
        
        for(int i = 0 ; i < 4 ; i++){
            ny = sy + dy[i];
            nx = sx + dx[i];
            if(0<=ny && ny<n && 0<=nx && nx<m && map[ny][nx] == 0){
                map[ny][nx] = map[sy][sx]+1;
                q.push(pos(ny, nx));
            }
            
        }
    }
    return map[n-1][m-1];
}

bool breakWall(int y, int x, int& minLen){
    int len;
    
    map[y][x] = 0;
    len = bfs(0, 0);
    
    if(len == 0)
        return false;
    
    minLen = min(minLen, len);
    map[y][x] = 1;
    return true;
}

void solve(){
    int len;
    int success;
    
    success = 0;
    len = INF;
    
    
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            if(y == 0 && x == 0 && breakWall(y, x, len)){
                success++;
                continue;
            }
            
            if(map[y][x] == 1 && breakWall(y, x, len))
                success++;
        }
    }
    
    if(success>0){
        cout<<len<<endl;
    }else{
        cout<<-1<<endl;
    }
    
}

void build(){
    map = vector<vector<int>>(n, vector<int>(m, 0));
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            scanf("%1d", &map[y][x]);
        
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    solve();
    return 0;
}

//
//  main.cpp
//  2178_미로탐색
//
//  Created by Kim Seong Jin on 06/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m;

int adj[101][101];

int dx[4] {0,1,0,-1};
int dy[4] {1,0,-1,0};

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    pair<int, int>here;
    int nx, ny;
    while(!q.empty()){
        here = q.front();
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            ny = here.first + dy[i];
            nx = here.second + dx[i];
            
            if((ny<0 || ny >= n) || (nx<0 || nx>=m))
                continue;
            
            if(adj[ny][nx]==1){
                q.push(make_pair(ny,nx));
                adj[ny][nx] = adj[here.first][here.second]+1;
            }
            
            
            
        }
    
    }
    
}



void build(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%1d", &adj[i][j]);
        }
    }
    //cout<<"Build ok"<<endl;
}



int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    bfs(0,0);
    cout<<adj[n-1][m-1]<<endl;
    return 0;
}

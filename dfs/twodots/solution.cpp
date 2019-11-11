//
//  main.cpp
//  16929_twodots
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#define MAX 51
using namespace std;

int sx, sy;
//h, w
int n, m;
//UDRL
int dy[] {-1, 1, 0, 0};
int dx[] {0 ,0, 1, -1};
vector<string>origin;
vector<string>table;
bool cycle;
void dfs(char color, int y, int x, int cnt){

    table[y][x] = ' ';
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny==sy && nx==sx && cnt>=3){
             cycle = true;
             return;
         }
        if(0<=nx && nx<m && 0<=ny && ny<n && table[ny][nx] == color){
            dfs(color, ny, nx, cnt+1);
        }
    }
}

void build(){
    origin = vector<string>(n);
    for(int y = 0 ; y<n ; y++){
        string s;
        cin>>origin[y];
    }
}

void print(){
    for(int y = 0 ; y<n ; y++){
        cout<<table[y]<<endl;
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    for(int y = 0 ; y<n ; y++){
        for(int x = 0 ; x<m ; x++){
            table = origin;
            sy = y;
            sx = x;
            dfs(table[y][x], y, x, 0);
            
            if(cycle){
                cout<<"Yes"<<endl;
                return 0;
            }
            
        }
    }
    cout<<"No"<<endl;
    return 0;
  
  
}

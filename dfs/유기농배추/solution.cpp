//
//  main.cpp
//  1012_유기농배추
//
//  Created by Kim Seong Jin on 13/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define MAX 2501

using namespace std;

int m,n;//width, height
int k;
int table[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void dfs(int y, int x){
    table[y][x] = 0;
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0<= ny && ny< n && 0 <= nx && nx < m && table[ny][nx] == 1){
            dfs(ny,nx);
        }
    }
}

void build(){
    int x, y;
    for(int i = 0 ; i < k ; i++){
        cin>>x>>y;
        table[y][x] = 1;
    }
}


void solve(){
    build();
    int cnt = 0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            if(table[y][x] == 1){
                dfs(y,x);
                cnt++;
            }
        }
       
    }
    cout<<cnt<<endl;
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        cin>>m>>n>>k;
        solve();
    }
    
    return 0;
}
/*
 1
 10 10 1
 5 5
 */

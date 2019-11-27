//
//  main.cpp
//  11048_이동하기
//
//  Created by Kim Seong Jin on 27/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 1001
using namespace std;
int n,m;
int map[MAX][MAX];
int dp[MAX][MAX];
int dy [3] {-1, 0, -1};
int dx [3] {0, -1, -1};

bool range(int y, int x){
    return 0<=y && y < n && 0<=x && x<m;
}

void candy(int y, int x){
    for(int i = 0 ; i < 3 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(range(ny, nx)){
            dp[y][x] = max(dp[y][x], dp[ny][nx]);
        }
    }
    dp[y][x] += map[y][x];
}

void solve(){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            candy(y, x);
        }
    }
    cout<<dp[n-1][m-1];
}

void build(){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cin>>map[y][x];
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    solve();
    return 0;
}

//
//  main.cpp
//  2667_단지번호붙이기
//
//  Created by Kim Seong Jin on 30/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>>adj;
//check
void bfs(int y, int x, int& cnt){
    adj[y][x] = 0;
    cnt++;
    if(y>0 && adj[y-1][x] == 1)
        bfs(y-1, x, cnt);
    if(y<n-1 && adj[y+1][x] == 1)
        bfs(y+1, x, cnt);
    if(x>0 && adj[y][x-1] == 1)
        bfs(y, x-1, cnt);
    if(x<n-1 && adj[y][x+1] == 1)
        bfs(y, x+1, cnt);
}

void build(int n){
    adj = vector<vector<int>>(n);
    for(int i = 0 ; i < n ; i++){
        adj[i] = vector<int>(n, 0);
        for(int j = 0 ; j < n ; j++){
            scanf("%1d", &adj[i][j]);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build(n);
    
    vector<int>towns;
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < n ; col++){
            if(adj[row][col]==1){
                int cnt = 0;
                bfs(row, col, cnt);
                towns.push_back(cnt);
            }
        }
    }
    sort(towns.begin(), towns.end());
    cout<<towns.size()<<endl;
    for(int t : towns)cout<<t<<endl;
    return 0;
}
/*
4
1111
1111
1111
1111
 */

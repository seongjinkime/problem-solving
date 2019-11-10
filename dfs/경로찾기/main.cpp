//
//  main.cpp
//  11403_findRoute
//
//  Created by Kim Seong Jin on 2019. 10. 21..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>>links;
vector<int> visited;


void dfs(int node, int here){
    links[node][here] = 1;
    visited[here] = 1;
    for(int i = 0 ; i < adj[here].size() ; i++){
        if(adj[here][i] == 1 && !visited[i]){
            dfs(node, i);
        }
    }
}

void markLinks(int n){
    for(int i = 0 ; i < n ; i++){
        visited = vector<int>(n, 0);
        for(int j = 0 ; j < n ; j++){
            if(adj[i][j]==1){
                dfs(i, j);
            }
        }
        
    }
}

void build(int n){
    adj = links = vector<vector<int>>(n, vector<int>(n, 0));
    visited = vector<int>(n, 0);
    for(int row = 0 ; row< n ; row++){
        for(int col = 0 ; col < n ; col++){
            cin>>adj[row][col];
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    build(n);
    markLinks(n);
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col<n ; col++){
            cout<<links[row][col]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

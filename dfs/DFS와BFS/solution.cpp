//
//  main.cpp
//  1260_DFS와BFS
//
//  Created by Kim Seong Jin on 18/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, v;
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int here){
    visited[here] = true;
    cout<<here<<" ";
    for(int i = 0 ; i < adj[here].size() ; i++){
        int there = adj[here][i];
        if(!visited[there]){
            dfs(there);
        }
    }
}

void bfs(int start){
    queue<int> q;
    visited = vector<bool>(n+1, false);
    q.push(start);
    visited[start] = true;
    cout<<start<<" ";
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        
        if(!visited[here]){
            cout<<here<<" ";
            visited[here] = true;
        }
        //
        
        for(int i = 0 ; i < adj[here].size() ; i++){
            int there = adj[here][i];
            if(!visited[there]){
                q.push(there);
            }
        }
        //for(bool b : visited)cout<<b<<" ";
        //cout<<endl;
    }
}

void build(){
    int a, b;
    adj = vector<vector<int>>(n+1);
    visited = vector<bool>(n+1, false);
    
    for(int i = 0 ; i < m ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1 ; i <= n ; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    /*
    for(int y = 1 ; y<=n ; y++){
        cout<<y<<" : ";
        for(int x = 0 ; x < adj[y].size() ; x++){
            cout<<adj[y][x]<<" ";
        }
        cout<<endl;
    }*/
}

int main(int argc, const char * argv[]) {
    cin>>n>>m>>v;
    build();
    dfs(v);
    cout<<endl;
    bfs(v);
    cout<<endl;
    return 0;
}

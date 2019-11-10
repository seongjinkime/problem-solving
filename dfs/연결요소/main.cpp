//
//  main.cpp
//  11724_components
//
//  Created by Kim Seong Jin on 2019. 10. 21..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>>adj;
vector<int>visited;

void dfs(int here){
    visited[here]=1;
    for(int i = 0 ; i < adj[here].size() ; i++){
        int there = adj[here][i];
        if(!visited[there]){
            dfs(there);
        }
    }
}

int dfsAll(int n){
    int cnt = 0;
    for(int i = 0 ; i<n ; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}

void build(int n, int m){
    adj = vector<vector<int>>(n, vector<int>());
    visited = vector<int>(n, 0);
    int start, end;
    for(int i = 0 ; i < m ; i++){
        cin>>start>>end;
        start-=1;
        end-=1;
        adj[start].push_back(end);
        //adj[end].push_back(start);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m;
    cin>>n>>m;
    build(n, m);
    cout<<dfsAll(n)<<endl;
    return 0;
}

/*
8 10
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3
3 2
7 8
 */

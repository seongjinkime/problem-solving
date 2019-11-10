//
//  main.cpp
//  2606_바이러스
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>adj;
vector<bool>visit;
int cnt;
int n;
int line;

void dfs(int here){
    visit[here] = true;
    cnt++;
    for(int i = 0 ; i < adj[here].size() ; i++){
        int there = adj[here][i];
        if(!visit[there]){
            dfs(there);
        }
    }
}

void build(){
    int a, b;
    cnt = 0;
    adj = vector<vector<int>>(n+1, vector<int>());
    visit = vector<bool>(n+1, false);
    for(int i = 0 ; i < line ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main(int argc, const char * argv[]) {
    
    cin>>n>>line;
    build();
    dfs(1);
    cout<<cnt-1<<endl;
    
    return 0;
}

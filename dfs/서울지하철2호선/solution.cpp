//
//  main.cpp
//  16947_서울지하철2호선
//
//  Created by Kim Seong Jin on 13/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

#define CYCLE 2
#define NOT_CYCLE -2

#define VISIT 1
#define NOT_VISIT 0

#define LEAF -1

using namespace std;

vector<vector<int>>adj;
vector<int>nodes, dist;
vector<bool> visited;

int n;

int findCycle(int here, int parent){
    if(nodes[here] != NOT_VISIT){
        return here;
    }
    
    nodes[here] = VISIT;
    
    for(int idx = 0 ; idx < adj[here].size() ; idx++){
        int there = adj[here][idx];
        if(there == parent)
            continue;
        int found = findCycle(there, here);
        
        if (found == NOT_CYCLE){
            return NOT_CYCLE;
        }
        
        if (found >= 0){
            nodes[here] = CYCLE;
            if(found == here)
                return NOT_CYCLE;
            else
                return found;
        }
    }
    
    return LEAF;
    
}

void bfs(){
    visited = vector<bool>(n+1, false);
    dist = vector<int>(n+1);
    queue<int> q;
    for(int i = 1 ; i<= n ; i++){
        if(nodes[i] == CYCLE){
            dist[i] = 0;
            visited[i] = true;
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0 ; i < adj[here].size() ; i++){
            int there = adj[here][i];
            if(visited[there])
                continue;
            visited[there] = true;
            dist[there] = dist[here] + 1;
            q.push(there);
        }
    }
}

void build(){
    int a, b;
    nodes = vector<int>(n+1);
    adj = vector<vector<int>>(n+1);
    for(int i = 0 ; i < n ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    findCycle(1, -1);
    bfs();
    for(int i = 1 ; i<= n ; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
 void cycle(int here, int there){
     while(parent[here] != parent[there]){
         cout<<here<<endl;
         here = parent[here];
     }
 }

 void makeGraph(int here){
     visited[here] = true;
     
     for(int i = 0 ; i < adj[here].size() ; i++){
         int there = adj[here][i];
         if(!visited[there]){
             parent[there] = here;
             makeGraph(there);
         }else if(!finished[there]){
             cout<<"FIND CYCLE: "<<here<<" "<<there<<endl;
             //cycle(here, there);
         }
     }
     
     finished[here] = true;
 }

 */

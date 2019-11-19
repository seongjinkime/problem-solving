//
//  main.cpp
//  16940_BFS스페셜저지
//
//  Created by Kim Seong Jin on 19/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

vector<int> orderCnt, discovered, input;
vector<vector<int>> adj;
int n;

void bfs(int start){
    queue<int> q;
    q.push(start);
    discovered[start] = 1;
    orderCnt[1] = 1;
    
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int i = 0 ; i < adj[here].size() ; i++){
            int there = adj[here][i];
            if(!discovered[there]){
                q.push(there);
                int visitOrder = discovered[here] + 1;
                discovered[there] = visitOrder;
                orderCnt[visitOrder]+=1;
            }
        }
    }
    
}

void build(){
    orderCnt = discovered = vector<int>(n+1, 0);
    input = vector<int>(n);
    adj = vector<vector<int>>(n+1);
    int a, b;
    
    for(int i = 0 ; i < n-1 ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 0 ; i < n ; i++){
        cin>>input[i];
    }
    
}

bool isAvailable(){
    int order = 1;
    int walker = 0;
    int cnt;
    
    while(walker < n){
        if(order >= orderCnt.size() || orderCnt[order] == 0)
            break;
        cnt = orderCnt[order];
        for(int i = 0 ; i < cnt ; i++){
            int num = input[walker];
            if(discovered[num] != order){
                return false;
            }
            walker++;
        }
        order++;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    bfs(1);
    cout<<isAvailable()<<endl;
    
    
    return 0;
}



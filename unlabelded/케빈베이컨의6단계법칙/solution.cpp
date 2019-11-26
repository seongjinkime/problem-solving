//
//  main.cpp
//  1389_케빈베이컨의6단계법칙
//
//  Created by Kim Seong Jin on 26/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;

vector<vector<int>> adj;
int n, m;

int kebin(int start){
    vector<int> discover = vector<int>(n+1, -1);
    queue<int> q;
    int sum = 0;
    
    q.push(start);
    discover[start] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0 ; i < adj[here].size() ; i++){
            int there = adj[here][i];
            if(discover[there] == -1){
                discover[there] = discover[here] + 1;
                q.push(there);
            }
        }
    }
    
    for(int d : discover){
        if(d!=-1) sum += d;
    }
    return sum;
}

void build(){
    adj = vector<vector<int>>(n+1);
    int a, b;
    for(int i = 0 ; i < m ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}


int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    int ret, k;
    
    k = MAX;
    for(int i = 1 ; i <= n ; i++){
        int n = kebin(i);
        if(k > n){
            ret = i;
            k = n;
        }
            
    }
    cout<<ret<<endl;
    return 0;
}

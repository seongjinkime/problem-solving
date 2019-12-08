//
//  main.cpp
//  12851_숨바꼭질2
//
//  Created by Kim Seong Jin on 29/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
#define INF 987654321
using namespace std;


int dist [MAX];
int cnt[MAX];
int n, k;



void bfs(int start){
    queue<int> q;
    q.push(start);
    
    fill_n(dist, MAX, INF);
    dist[start] = 0;
    cnt[start] = 1;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        vector<int> pos {here-1, here+1, here*2};
        
        for(int idx = 0 ; idx < 3 ; idx++){
            int nx = pos[idx];
            if(0<=nx && nx < MAX ){
                if(dist[nx] > dist[here]+1){
                    dist[nx] = dist[here]+1;
                    cnt[nx] = cnt[here];
                    q.push(nx);
                }else if(dist[nx] == dist[here]+1){
                    cnt[nx] = cnt[nx] + cnt[here];
                }
                //cout<<nx<<endl;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    bfs(n);
    cout<<dist[k]<<endl;
    cout<<cnt[k]<<endl;
    
    return 0;
}

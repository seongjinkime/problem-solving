//
//  main.cpp
//  1504_특정한최단경로
//
//  Created by Kim Seong Jin on 23/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;
typedef pair<int, int> pr;

vector<vector<pr>> adj;
int n, e;

int dist(int start, int end){
    vector<int> d = vector<int>(n+1, INF);
    priority_queue<pr, vector<pr>, greater<pr>> q;
    
    d[start] = 0;
    q.push(pr(0, start));
    
    while (!q.empty()) {
        int cost = q.top().first;
        int here = q.top().second;
        
        q.pop();
        
        for(int i = 0 ; i<adj[here].size() ; i++){
            int there = adj[here][i].first;
            int ncost = cost + adj[here][i].second;
            
            if(d[there] > ncost){
                d[there] = ncost;
                q.push(pr(ncost, there));
            }
        }
    }
    return d[end];
}

void build(){
    adj = vector<vector<pr>>(n+1);
    int u, v, w;
    for(int i = 0 ; i < e ; i++){
        cin>>u>>v>>w;
        adj[u].push_back(pr(v, w));
        adj[v].push_back(pr(u, w));
    }
}

int main(void){
    int x, y;
    cin>>n>>e;
    build();
    cin>>x>>y;
    
    int a = dist(1, x) + dist(x, y) + dist(y, n);
    int b = dist(1, y) + dist(y, x) + dist(x, n);
    int ret = min(a, b);
    if(ret >= INF || ret < 0){
        cout<<-1<<endl;
    }else{
        cout<<ret<<endl;
    }
    
}

/*
vector<int> dijkstra(int start){
    vector<int> dist = vector<int>(n+1, INF);
    priority_queue<pr, vector<pr>, greater<pr>> q;
    dist[start] = 0;
    q.push(pr(0, start));
    
    while (!q.empty()) {
        int cost = q.top().first;
        int here = q.top().second;
        q.pop();
        for(int i = 0 ; i < adj[here].size() ; i++){
            int there = adj[here][i].first;
            int ncost = cost + adj[here][i].second;
            if(there>start && dist[there] > ncost){
                dist[there] = ncost;
                q.push(pr(ncost, there));
            }
        }
    }
    
    return dist;
}

void build(){
    adj = vector<vector<pr>>(n+1);
    int u, v, w;
    for(int i = 0 ; i < e ; i++){
        cin>>u>>v>>w;
        adj[u].push_back(pr(v, w));
        adj[v].push_back(pr(u, w));
    }
}

int main(void){
    vector<int> dist;
    int a, b;
    cin>>n>>e;
    build();
    cin>>a>>b;
    
    dist = dijkstra(1);

    int t = -1;
    for(int i = 0 ; i < adj[a].size() ; i++){
        if(adj[a][i].first == b)
            t = adj[a][i].second;
    }
    
    if(t == -1){
        cout<<"-1"<<endl;
    }else{
        dist = dijkstra(1);
        t += dist[a];
        dist = dijkstra(b);
        t += dist[n];
        
        cout<<t<<endl;
    }
}

*/

/*
#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;
typedef pair<int, int> pr;
vector<vector<pr>> adj;
int n, e;
int cu, cv;

vector<int> dijkstra(int start){
    vector<int> dist = vector<int>(n+1, INF);
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    dist[start] = 0;
    pq.push(pr(0, start));
    
    while(!pq.empty()){
        int hcost= pq.top().first;
        int here = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < adj[here].size() ; i++){
            int there = adj[here][i].first;
            int ncost = hcost + adj[here][i].second;
            
            if(dist[there] > ncost){
                dist[there] = ncost;
                pq.push(pr(ncost, there));
            }
            
            if((here == cu && there == cv)){
                dist[there] = ncost;
                pq.push(pr(ncost, there));
                continue;
            }
            if(dist[there] > ncost){
                    dist[there] = ncost;
                    pq.push(pr(ncost, there));

            }
        }
    }
    return dist;
}

void build(){
    adj = vector<vector<pr>>(n+1);
    int u, v, w;
    for(int i = 0 ; i < e ; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(pr(v, w));
        adj[v].push_back(pr(u, w));
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>e;
    build();
    cin>>cu>>cv;
    vector<int> dist = dijkstra(1);
    for(int i = 1 ; i <= n ; i++){
        cout<<dist[i]<<endl;
    }
    return 0;
}
*/

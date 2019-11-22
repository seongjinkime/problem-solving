//
//  main.cpp
//  1753_최단경로
//
//  Created by Kim Seong Jin on 22/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//
/*
 다익스트라 Sudo code
 
 시작점을 0으로 초기화
 모든 곳을 방문하기 전까지
    아직 방문하지 않은 곳 중 가장 짧은 거리의 노드를 선택한다
    방문 처리
    방문하지 않은 인접 노드를 순회하며
        자신을 거쳐 지나간 거리가 기존 값 보다 짧다면
            인접 노드의 거리비용을 업데이트 한다.
 
 */
#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

vector<vector<int>> graph;
int vertex, edge;

vector<int>dijkstra(int start){
    vector<int> dist = vector<int>(vertex, INF);
    vector<bool> visited = vector<bool>(vertex, false);
    int visit= 0;
    int node = start;
    
    dist[start-1] = 0;
    
    while(visit<vertex){
        int cost = INF;
        for(int i = 0 ; i < dist.size() ; i++){
            if(!visited[i] && cost > dist[i]){
                cost = dist[i];
                node = i;
            }
        }
        
        visited[node] = true;
        visit++;
        
        for(int i = 0 ; i < dist.size() ; i++){
            if(visited[i])
                continue;
            dist[i] = min(dist[i], dist[node] + graph[node][i]);
        }
        
    }
    return dist;
    
}

void build(){
    graph = vector<vector<int>>(vertex, vector<int>(vertex, INF));
    int u, v, w;
    for(int i = 0 ; i < vertex ; i++){
        cin>>u>>v>>w;
        graph[u-1][v-1] = w;
    }
}

int main(int argc, const char * argv[]) {
    int start;
    cin>>vertex>>edge>>start;
    build();
    vector<int> dist = dijkstra(start);
    for(int i = 0 ; i < dist.size() ; i++){
        if(dist[i] == INF){
            cout<<"INF"<<endl;
        }else{
            cout<<dist[i]<<endl;
        }
    }
    return 0;
}

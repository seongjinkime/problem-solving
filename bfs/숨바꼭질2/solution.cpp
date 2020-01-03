//
//  main.cpp
//  12851_숨바꼭질2
//
//  Created by Kim Seong Jin on 29/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>
#define MAX 100001

using namespace std;

int arr[MAX];
int paths[MAX];
map<int, int> dist;

int n, k;
bool inRange(int x){
    return 0<=x && x< MAX;
}

bool visited(int x){
    return dist.count(x) > 0;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    paths[start] = 1;
    
    while(!q.empty()){
        int here = q.front();
        q.pop();
        
        for(int npos : {here+1, here-1, here*2}){
            if(!inRange(npos))
                continue;
            if(!visited(npos)){
                dist[npos] = dist[here]+1;
                paths[npos] = paths[here];
                q.push(npos);
            }else if(dist[npos] == dist[here]+1){
                paths[npos] += paths[here];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    bfs(n);
    cout<<dist[k]<<endl;
    cout<<paths[k]<<endl;
    
    return 0;
}

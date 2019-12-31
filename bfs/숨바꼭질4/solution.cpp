//
//  main.cpp
//  13913_숨바꼭질4(retry)
//
//  Created by Kim Seong Jin on 2019. 12. 31..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <stack>
#define MAX 100001

using namespace std;

int arr[MAX];
int parent[MAX];
map<int, int> dist;
int n, k;

void printPath(int x){
    stack<int>s;
    while(x != -1){
        s.push(x);
        x = parent[x];
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
}

bool inRange(int x){
    return 0<=x && x< MAX;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    parent[start] = -1;
    
    while(!q.empty()){
        int here = q.front();
        q.pop();
        if(here == k){
            cout<<dist[here]<<endl;;
            printPath(here);
            cout<<endl;
            return;
        }
        int npos[3] {here+1, here-1, here*2};
        for(int pos : npos){
            if(!inRange(pos))
                continue;
            if(dist.count(pos)>0)
                continue;
            parent[pos] = here;
            dist[pos] = dist[here]+1;
            q.push(pos);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    bfs(n);
    
    return 0;
}

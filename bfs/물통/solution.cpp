//
//  main.cpp
//  2251_물통
//
//  Created by Kim Seong Jin on 2019. 11. 28..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef vector<int> buckets;
buckets size;
vector<int>waters;

void moveWater(buckets& w, int src, int dst){
    if(w[src] > (size[dst] - w[dst])){
        w[src] -=(size[dst] - w[dst]);
        w[dst] = size[dst];
    }else{
        w[dst] += w[src];
        w[src] = 0;
    }
}

void bfs(buckets start){
    buckets nb;
    queue<buckets> q;
    q.push(start);
    set<buckets> visited;
    visited.insert(start);
    
    while(!q.empty()){
        buckets current = q.front();
        q.pop();
        
        if(current[0] == 0)
            waters.push_back(current[2]);
        
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(i==j)
                    continue;
                nb = current;
                moveWater(nb, i, j);
                if(visited.count(nb)>0)
                    continue;
                visited.insert(nb);
                q.push(nb);
            }
        }
    }
}

void build(buckets& start){
    start = buckets(3, 0);
    size = buckets(3);
    for(int i = 0 ; i < 3 ; i++){
        cin>>size[i];
    }
    start[2] = size[2];
}

int main(int argc, const char * argv[]) {
    buckets start;
    build(start);
    
    bfs(start);
    sort(waters.begin(), waters.end());
    for(int w : waters)
        cout<<w<<" ";
    cout<<endl;
    //cout<<waters.size()<<endl;
    
    return 0;
}

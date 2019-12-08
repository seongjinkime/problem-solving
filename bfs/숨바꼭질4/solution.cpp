//
//  main.cpp
//  13913_숨바꼭질4
//
//  Created by Kim Seong Jin on 26/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#define MAX 100000 + 1

using namespace std;
typedef struct _WALKER{
    int pos;
    vector<int> path;
    _WALKER(int _p){ pos = _p;}
    
}walker;

int map[MAX];
int n, k;

void bfs(int start){
    queue<walker> q;
    map[start] = 1;
    q.push(walker(start));
    
    
    while(!q.empty()){
        walker w = q.front();
        int here = w.pos;
        q.pop();
        
        if(here ==k){
            cout<<map[here]-1<<endl;
            printf("%d ", start);
            for(int p : w.path){
                printf("%d ", p);
                //cout<<p<<" ";
            }
            cout<<endl;
            return;
        }
       
        vector<int> newPos {here+1, here-1, here*2};
        
        for(int nx : newPos){
            if(0<=nx && nx < MAX && map[nx] == 0){
                map[nx] = map[here]+1;
                //w.path.push_back(nx);
                //w.pos = nx;
                walker nw = walker(nx);
                nw.path = vector<int>(w.path.begin(), w.path.end());
                nw.path.push_back(nx);
                q.push(nw);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    bfs(n);
    return 0;
}

//
//  main.cpp
//  1697_숨바꼭질
//
//  Created by Kim Seong Jin on 18/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <queue>

#define INF 987654321
#define MAX 100001

using namespace std;

int map[MAX];
int n, k;


void bfs(int start){
    int here, there;
    queue<int>q;
    map[start] = 1;
    vector<int> theres (3);
    q.push(start);
    
    while (!q.empty()) {
        here = q.front();
        q.pop();
        if(here == k){
            cout<<map[here]-1<<endl;
            return;
        }
        theres[0] = here * 2;
        theres[1] = here + 1;
        theres[2] = here - 1;
        
        for(int i = 0 ; i < 3 ; i++){
            there = theres[i];
            if(0 <= there && there < MAX && map[there] == 0){
                q.push(there);
                map[there] = map[here]+1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    bfs(n);

    return 0;
}

//5 99999


/*
vector<bool>visit;
int n, k;
long long ret;
bool isSame;
void dfs(int here, long long cnt){
    
    isSame= here == k;
    cout<<here<<endl;
    if(isSame){
        if(ret > cnt){
            ret = cnt;
        }
        //cout<<"is Same"<<endl;
        return;
    }
    visit[here] = true;
    vector<int> newPos {here * 2, here + 1, here - 1};
    for(int i = 0 ; i < 3 ; i++){
        int there = newPos[i];
        if(!isSame && there < visit.size() && !visit[there] ){
            dfs(there, cnt+1);
        }
    }
}

int main(int argc, const char * argv[]) {
    ret = INF;
    cin>>n>>k;
    visit = vector<bool>(max(n, k) + 2, false);
    dfs(n, 0);
    cout<<ret<<endl;
    return 0;
}

//99999 100000
*/

//
//  main.cpp
//  2422_한윤정이이탈리아에가서아이스크림을사먹는데
//
//  Created by Kim Seong Jin on 2020. 1. 5..
//  Copyright © 2020년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 201
using namespace std;
vector<vector<int>> danger;
bool selected[MAX];
int n,m, cnt;


bool available(){
    bool res = true;
    for(int i = 0 ; i < n ; i++){
        if(!selected[i]) continue;
        
        for(int j = 0 ; j < danger[i].size() ; j++){
            int dangerNum = danger[i][j];
            if(selected[dangerNum]){
                res= false;
            }
        }
        
    }
    
    if(res == true)
        cnt++;
    return res;
}

void dfs(int here, int cnt){
    if(cnt == 3){
        available();
        return;
    }
    
    for(int there = here ; there < n ; there++){
        if(!selected[there]){
            selected[there] = true;
            dfs(there, cnt+1);
            selected[there] = false;
        }
    }
}


void build(){
    int a, b;
    cnt = 0;
    cin>>n>>m;
    danger = vector<vector<int>>(n);
    
    for(int i = 0 ; i < m ; i++){
        cin>>a>>b;
        a-=1;
        b-=1;
        
        danger[a].push_back(b);
        danger[b].push_back(a);
    }
}


int main(int argc, const char * argv[]) {
    build();
    dfs(0,0);
    cout<<cnt<<endl;
    return 0;
}

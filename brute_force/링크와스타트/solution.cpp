//
//  main.cpp
//  15661_링크와스타트
//
//  Created by Kim Seong Jin on 15/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 21
#define INF 987654321
using namespace std;

vector<bool>selected;
int table [MAX][MAX];
int n, ret;

int getStat(vector<int> members){
    int sum = 0;
    
    if(members.size() == 1){
        return 0;
    }else{
        int pa, pb;
        for(int i = 0 ; i < members.size(); i++){
            pa = members[i];
            for(int j = i + 1 ; j < members.size() ; j++){
                pb = members[j];
                sum += table[pa][pb] + table[pb][pa];
            }
        }
    }
    return sum;
}

void divide(vector<int>& start, vector<int>& link){
    for(int i = 0 ; i < n ; i++){
        if(selected[i])
            start.push_back(i);
        else
            link.push_back(i);
    }
}


void compare(){
    vector<int> start, link;
    int statA, statB;
    
    divide(start, link);
    statA = getStat(start);
    statB = getStat(link);
    ret = min(ret, abs(statA - statB));
    
}

void dfs(int here, int cnt){
    if(0<cnt && cnt<n-1)
        compare();
    
    for(int there = here ; there < n ; there++){
        if(!selected[there]){
            selected[there] = true;
            dfs(there, cnt+1);
            selected[there] = false;
        }
    }
    
}

void build(){
    ret = INF;
    selected = vector<bool>(n+1);
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cin>>table[y][x];
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    dfs(0, 0);
    cout<<ret<<endl;
    return 0;
}

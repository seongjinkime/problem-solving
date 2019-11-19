//
//  main.cpp
//  1024_최빈수구하기
//
//  Created by Kim Seong Jin on 19/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 1000
using namespace std;

typedef pair<int, int> info;
vector<info> scores;

bool comp(info a, info b){
    if(a.second == b.second){
        return a.first > b.first;
    }else{
        return a.second > b.second;
    }
}

void build(){
    int num;
    scores = vector<info>();
    for(int i = 0 ; i <= 100 ; i++){
        scores.push_back(info(i, 0));
    }
    
    for(int i = 0 ; i < MAX ; i++){
        cin>>num;
        scores[num].second+=1;
    }
}

void solve(int t){
    int tmp;
    cin>>tmp;
    build();
    sort(scores.begin(), scores.end(), comp);
    printf("#%d %d\n", tmp, scores[0].first);
    
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        solve(i);
    }
    
    
    return 0;
}

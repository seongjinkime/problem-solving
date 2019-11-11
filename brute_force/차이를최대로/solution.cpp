//
//  main.cpp
//  10891_차이를최대로
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 9
using namespace std;

vector<int>permutation;
vector<bool>selected;
vector<int>nums;

int n, ret;

void sum(){
    int total = 0;
    for(int i = 0 ; i < permutation.size()-1 ; i++){
        total += abs(permutation[i] - permutation[i+1]);
    }
    ret = max(ret, total);
}

void dfs(int start, int cnt){
    if(cnt==n){
        sum();
        return;
    }
    for(int i = 0; i<nums.size() ; i++){
        if(!selected[i]){
            selected[i]=true;
            permutation.push_back(nums[i]);
            dfs(i, cnt+1);
            permutation.pop_back();
            selected[i]=false;
        }
    }
}

void build(){
    ret = 0;
    nums = vector<int>(n);
    selected = vector<bool>(n, false);
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    dfs(0, 0);
    cout<<ret<<endl;
    
    return 0;
}

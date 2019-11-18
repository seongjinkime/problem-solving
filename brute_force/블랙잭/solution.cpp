//
//  main.cpp
//  2798_블랙잭
//
//  Created by Kim Seong Jin on 18/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int>nums;
vector<int>permutation;
vector<bool> selected;

int n,m;
int ret;
void check(){
    int sum = 0;
    for(int i = 0 ; i < 3 ; i++){
        //cout<<permutation[i]<<" ";
        sum += permutation[i];
    }
    
    if(sum <= m){
        ret = max(ret, sum);
    }
}

void dfs(int cnt){
    if(cnt==3){
        check();
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(!selected[i]){
            selected[i] = true;
            permutation.push_back(nums[i]);
            dfs(cnt+1);
            permutation.pop_back();
            selected[i] = false;
        }
    }
}

void build(){
    nums = vector<int>(n);
    selected = vector<bool>(n, false);
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    dfs(0);
    cout<<ret<<endl;
    return 0;
}

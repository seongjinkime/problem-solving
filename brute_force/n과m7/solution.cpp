//
//  main.cpp
//  15656_n과m7
//
//  Created by Kim Seong Jin on 08/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>nums;
vector<int>permutaion;

int n,m;

void print(){
    for(int i = 0 ; i < permutaion.size() ; i++){
        printf("%d ", permutaion[i]);
    }
    printf("\n");
}

void dfs(int cnt){
    if(cnt==m){
        print();
        return;
    }
    for(int i = 0 ; i < n ; i++){
        permutaion.push_back(nums[i]);
        dfs(cnt+1);
        permutaion.pop_back();
    }
}

void build(){
    nums = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
}


int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    dfs(0);
    
    return 0;
}

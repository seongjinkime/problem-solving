//
//  main.cpp
//  15654_n과m5
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
vector <bool> visited;
vector <int> permutation;
vector <int> nums;

void print(){
    for(int i = 0 ; i < permutation.size() ; i++){
        printf("%d ", permutation[i]);
    }
    printf("\n");
}

void dfs(int cnt){
    if(cnt==m){
        print();
        return;
    }
    
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            visited[i]=true;
            permutation.push_back(nums[i]);
            dfs(cnt+1);
            permutation.pop_back();
            visited[i]=false;
        }
    }
}

void build(){
    visited = vector<bool>(n);
    nums = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &nums[i]);
    }
    sort(nums.begin(), nums.end());
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    build();
    dfs(0);
    return 0;
}

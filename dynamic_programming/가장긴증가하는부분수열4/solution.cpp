//
//  main.cpp
//  14002_가장긴증가하는부분수열4
//
//  Created by Kim Seong Jin on 12/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int>arr, dp;
vector<vector<int>> nums;
int n;

void build(){
    arr = dp = vector<int>(n+1, 0);
    nums = vector<vector<int>>(n+1, vector<int>());
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    
}

void solve(){
    build();
    int maxIdx = 0;
    for(int i = 1 ; i <= n ; i++){
        vector<int>tmp;
        for(int j = 0 ; j<=i ; j++){
            if(arr[i]>arr[j]){
                if(dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    tmp = nums[j];
                }
            }
        }
        nums[i] = tmp;
        nums[i].push_back(arr[i]);
        if(dp[i]>dp[maxIdx]){
            maxIdx = i;
        }
    }
    
    cout<<dp[maxIdx]<<endl;
    for(int i = 0 ; i<nums[maxIdx].size() ; i++){
        cout<<nums[maxIdx][i]<<" ";
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    solve();
    return 0;
}

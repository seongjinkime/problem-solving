//
//  main.cpp
//  11053_가장긴증가하는부분수열
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main(int argc, const char * argv[]){
    vector<int>arr, dp, nums;
    int most = 0;
    int n;
    cin>>n;
    int ret = 0;
    arr = dp = vector<int>(n+1, 0);
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    
    //dp[0]=1;
    
    for(int i = 1 ; i <= n ; i++){
        int maxIdx = 0;
        vector<int>tmp = vector<int>();
        for(int j = 0 ; j < i ; j++){
            if(arr[j]<arr[i]){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    maxIdx = j;
                }
            }
            ret = max(dp[i], ret);
            for(int k = 0 ; k<=maxIdx ; k++){
                tmp.push_back(arr[k]);
            }
            tmp.push_back(arr[i]);
            if(nums.size()<tmp.size()){
                nums = tmp;
            }
        }
    }
    cout<<ret<<endl;
    for(int i : nums)cout<<nums[i]<<" ";
    
    
    return 0;
}
/*
 8
 7 8 2 5 9 3 1 2
 */

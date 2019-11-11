//
//  main.cpp
//  1912_연속합
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;

long long dp[MAX];
long long arr[MAX];
int n;

void solve(){
    
    long long ret = 0;
    
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    dp[0] = arr[0];
    ret = arr[0];
    for(int i = 1; i < n ; i++){
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
        ret = max(ret, dp[i]);
    }
    
    for(int i = 0 ; i < dp)
    
    cout<<ret<<endl;
}

int main(int argc, const char * argv[]) {
    cin>>n;
    solve();
    return 0;
}

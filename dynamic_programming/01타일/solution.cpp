//
//  main.cpp
//  1904_01타일
//
//  Created by Kim Seong Jin on 20/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 1000000 + 1
#define mod 15746

using namespace std;
int dp[MAX];
int dfs(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 3;
    if(dp[n]!=0)return dp[n];
    
    dp[n] = (dfs(n-1) + dfs(n-2))%mod;
    
    return dp[n];
}

void solve(int num){
    for(int i = 0 ; i <= 3 ; i++)
        dp[i] = i;
    for(int i = 4 ; i <= num ; i++){
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }
    cout<<dp[num]<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    solve(n);

    return 0;
}

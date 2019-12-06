//
//  main.cpp
//  2293_동전1
//
//  Created by Kim Seong Jin on 05/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 10001
using namespace std;
int coins[101];
int dp[MAX];
int n,k;

void solve(){
    //dp[i] = dp[i-coins[i]]
    dp[0] = 1;
    for(int i = 0 ; i < n ; i++){
        int coin = coins[i];
        for(int num = coin ; num <= k ; num++){
            dp[num] += dp[num-coin];
        }
    }
    cout<<dp[k]<<endl;
}

void build(){
    cin>>n>>k;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i];
    }
}

int main(int argc, const char * argv[]) {
    build();
    solve();
    return 0;
}

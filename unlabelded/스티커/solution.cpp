//
//  main.cpp
//  9465_스티커
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 1000001

using namespace std;
int cost[2][MAX];
int dp[2][MAX];

void solve(){
    int n, res;
    cin>>n;
    for(int row = 0 ; row < 2 ; row++){
        for(int col = 1 ; col<=n ; col++){
            cin>>cost[row][col];
        }
    }
    
    dp[0][1] = cost[0][1];
    dp[1][1] = cost[1][1];
    
    for(int i = 2 ; i <= n ; i++){
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + cost[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + cost[1][i];
    }
    
    res = max(dp[0][n], dp[1][n]);
    cout<<res<<endl;
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        solve();
    }
    return 0;
}

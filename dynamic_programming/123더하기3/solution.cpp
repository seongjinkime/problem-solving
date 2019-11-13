//
//  main.cpp
//  15988_123더하기3
//
//  Created by Kim Seong Jin on 13/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define mod 1000000009
#define MAX 1000001

using namespace std;

typedef long long LL;
LL dp[MAX];

void solve(int n){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4 ; i <= n ; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;
    }
    cout<<dp[n]<<endl;
}

int main(int argc, const char * argv[]) {
    int t, n;
    cin>>t;
    
    for(int i = 0 ; i < t ; i++){
        cin>>n;
        solve(n);
    }

    return 0;
}

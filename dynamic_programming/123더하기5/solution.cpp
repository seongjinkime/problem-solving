//
//  main.cpp
//  15990_123더하기5
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define MAX  100001
#define mod 1000000009

using namespace std;

typedef long long ll;
ll dp[MAX][4];

ll solution(int n){
    dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    ll ret = dp[n][1] + dp[n][2] + dp[n][3];
    if(ret != 0) return ret % mod;
    
    ll sum;
    for(int current = 4 ; current <= n ; current++){
        
        if(dp[current][1] + dp[current][2] + dp[current][3] != 0)continue;
        for(int walker = 1 ; walker <= 3 ; walker++){
            sum = 0;
            for(int col = 1 ; col <= 3 ; col++){
                if(walker==col)continue;
                sum = (sum+dp[current-walker][col]) % mod;
            }
            dp[current][walker] = sum;
        }
        
    }
    
    return (dp[n][1] + dp[n][2] + dp[n][3]) % mod;
    
}

int main(int argc, const char * argv[]) {
    int t,n;
    cin>>t;
    while(t-->0){
        cin>>n;
        cout<<solution(n)<<endl;
    }
    return 0;
}

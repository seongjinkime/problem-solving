//
//  main.cpp
//  1699_제곱수의합
//
//  Created by Kim Seong Jin on 13/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <math.h>
#define MAX 100001

using namespace std;

long long dp[MAX];
long long msqrt = 1;

void solve(int n){
    for(int i = 1 ; i <= n ; i++){
        dp[i] = i;
    }

    for(int i = 1 ; i<= n ; i++){
        for(int j = 2 ; j*j <= i ; j++){
            dp[i] = min(dp[i], dp[i-(j*j)]+1);
        }
        
    }

    cout<<dp[n]<<endl;
}


int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    
    solve(n);
    //cout<<sqrt(11)<<endl;
    
    return 0;
}

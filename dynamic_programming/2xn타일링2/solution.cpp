//
//  main.cpp
//  11727_2xn타일링2
//
//  Created by Kim Seong Jin on 02/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>

using namespace std;

int dp[1001];

int main(){
    int n;
    cin>>n;
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2 ; i <= n ; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-2]) % 10007;
    
    cout<<dp[n]<<endl;
}

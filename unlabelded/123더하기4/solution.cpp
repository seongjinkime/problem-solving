//
//  main.cpp
//  15989_123더하기4
//
//  Created by Kim Seong Jin on 17/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 10002

using namespace std;

int dp[MAX][3];


void build(){
    dp[1][0] = 1;
    dp[1][1] = dp[1][2] = 0;
    
    dp[2][0] = dp[2][1] = 1;
    dp[2][2] = 0;
    
    dp[3][0] = dp[3][1] = dp[3][2] = 1;
    
    for(int i = 4 ; i < MAX ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k <= j ; k++){
                dp[i][j] += dp[i-j-1][k];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    build();
    int t, n;
    cin>>t;
    for(int i = 0 ; i < t; i++){
        cin>>n;
        cout<<dp[n][0] + dp[n][1] + dp[n][2]<<endl;
    }
    
    return 0;
}

//
//  main.cpp
//  1149_RGB거리
//
//  Created by Kim Seong Jin on 15/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define MAX 1001

using namespace std;

int cost[MAX][3];
int dp[MAX][MAX];
int colored;
int n;


void solve(){
    int ret;
    
    for(int i = 0 ; i < 3 ; i++)
        dp[0][i] = cost[0][i];
    
    for(int i = 1 ; i< n ; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    ret = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    cout<<ret<<endl;
    
}

void build(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin>>cost[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    solve();
    return 0;
}

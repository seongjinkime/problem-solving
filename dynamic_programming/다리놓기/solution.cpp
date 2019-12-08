//
//  main.cpp
//  1010_다리놓기
//
//  Created by Kim Seong Jin on 04/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MAX 31
using namespace std;

int n,m;
int dp[MAX][MAX];

void solve(){
    cin>>n>>m;
    memset(dp, 0, sizeof(dp));
    for(int i = 1 ; i <= m ; i++){
        dp[1][i] = i;
    }
    
    for(int node = 2 ; node <= n ; node++){
        for(int dst = node ; dst <= m ; dst++){
            for(int subDst = node ; subDst <= dst ; subDst++){
                //printf("%d %d += %d %d\n", node, dst, node-1, subDst-1);
                dp[node][dst] += dp[node-1][subDst-1];
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 0 ; i < t; i++)
        solve();
    return 0;
}

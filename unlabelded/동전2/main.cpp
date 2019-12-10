//
//  main.cpp
//  2294_동전
//
//  Created by Kim Seong Jin on 06/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 101
#define INF 987654321

using namespace std;
typedef long long LL;
int dp[100001];
int coins[101];
int n, k;

int solve(int n){
    for(int i = 0 ; i <= k ; i++)
        dp[i] = INF;
    
    for(int i = 0 ; i< n ; i++){
        dp[coins[i]] = 1;
    }
    
    
    for(int money = 1 ; money<= k ; money++){
        for(int idx = 0 ; idx < n ; idx++){
            int coin = coins[idx];
            if(coin>money) continue;
            for(int cnt = 1 ; cnt*coin < money ; cnt++){
                dp[money] = min(dp[money], dp[money-(cnt*coin)]+cnt);
            }
        }
    }
    
    
    return dp[k];
}

void build(){
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i];
    }
}


int main(int argc, const char * argv[]) {
    cin>>n>>k;
    build();
    int ret = solve(n);
    if(ret == INF){
        cout<<-1<<endl;
    }else{
        cout<<ret<<endl;
    }
    
    
    return 0;
}

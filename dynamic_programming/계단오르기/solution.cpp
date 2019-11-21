//
//  main.cpp
//  2579_계단오르기_retry
//
//  Created by Kim Seong Jin on 21/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 301

using namespace std;

int stairs[MAX];
int scores[MAX];
int dp[MAX];
int n;

int solve(int n){
    
    for(int i = 4 ; i <= n ; i++){
        int a = stairs[i-2] + scores[i];
        int b = stairs[i-3] + scores[i-1] + scores[i];
        //cout<<a<<" : "<<b<<endl;
        stairs[i] = max(a, b);
    }
    
    return stairs[n];
    
    
}

int dfs(int n){
    if(n<3)
        return stairs[n];
    if(dp[n] != 0)
        return dp[n];
    int a = dfs(n-2) + scores[n];
    int b = dfs(n-3) + scores[n-1] + scores[n];
    dp[n] = max(a,b);
    return dp[n];
    
}

void init(){
    for(int i = 1 ; i <= n ; i++)
        cin>>scores[i];
    
    stairs[1] = scores[1];
    stairs[2] = scores[1] + scores[2];
    stairs[3] = max(scores[1] + scores[3], scores[2] + scores[3]);
}

int main(int argc, const char * argv[]) {
    cin>>n;
    init();
    //cout<<scores[n]<<endl;
    //cout<<solve(n)<<endl;
    cout<<dfs(n);
    return 0;
}

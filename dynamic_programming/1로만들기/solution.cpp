//
//  main.cpp
//  1463_1로만들기
//
//  Created by Kim Seong Jin on 30/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int dp[n+1];
    dp[1] = 0;
    
    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1]+1;
        if(i%2 == 0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }
    }
    cout<<dp[n];
    
}

/*
using namespace std;

int solutionB(int n){
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4 ; i <= n ; i++){
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0){
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }
    return dp[n];
}

int solutionA(int n){
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i = 4 ; i <= n ; i++){
        if(i%2==0 && i%3 == 0){
            dp[i] = min(dp[i/2]+1, dp[i/3]+1);
        }else if (i%3 == 0 && i%2 != 0){
            dp[i] = dp[i/3]+1;
        }else if (i%2 == 0 && i%3 != 0){
            dp[i] = dp[i/2]+1;
        }else if (i%2 != 0 && i%3 != 0){
            dp[i] = dp[i-1] + 1;
        }
    }
    for(int i : dp)cout<<i<<" ";
    cout<<endl;
    //1 1 1 2 3 2 3 3 2 3
    return dp[n];
}

int main(int argc, const char * argv[]) {
    //long long n;
    //cin>>n;
    cout<<solutionA(10)<<" "<<solutionB(10)<<endl;
    return 0;
    for(int i = 1 ; i < 10000000 ; i++){
        if(solutionA(i) != solutionB(i)){
            cout<<i<<endl;
            break;
        }
        
    }

    return 0;
}
*/

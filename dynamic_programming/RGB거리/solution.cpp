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

int table[MAX][3 ];
int dp[MAX];
int colored;
int n;

int getMin(int row){
    int ret = MAX;
    for (int i = 0 ; i < 3 ; i++){
        if(i==colored)
            continue;
        if(ret > table[row][i]){
            ret = table[row][i];
            colored = i;
        }
    }
    return ret;
}

void solve(){
    colored = -1;
    dp[0] = getMin(0);
    for(int i = 1 ; i < n ; i++){
        dp[i] = dp[i-1] + getMin(i);
    }
    cout<<dp[n-1]<<endl;
}

void build(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin>>table[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    solve();
    return 0;
}

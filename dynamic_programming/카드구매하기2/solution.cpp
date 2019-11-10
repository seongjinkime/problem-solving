//
//  main.cpp
//  16194_카드구매하기2
//
//  Created by Kim Seong Jin on 05/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;

int d[1002];
int card[1002];

int dp(int n){
    if(n==0)return 0;
    if(d[n]>0)return d[n];
    int ret = card[n];
    for(int i = 1 ; i<= n ; i++){
        ret = min(ret, dp(n-i)+card[i]);
    }
    return d[n] = ret;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>card[i];
    }
    cout<<dp(n)<<endl;
    return 0;
}

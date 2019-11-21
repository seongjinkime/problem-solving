//
//  main.cpp
//  2156_포도주시식
//
//  Created by Kim Seong Jin on 21/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 10001

using namespace std;
typedef long long LL;
int amt[MAX];
LL dp[MAX];
LL accum[MAX];


int n;


void build(){
    for(int i = 1; i<=n ; i++)
        cin>>amt[i];
    accum[0] = 0;
    accum[1] = amt[1];
    accum[2] = amt[1] + amt[2];
    accum[3] = max(amt[1] + amt[3], amt[2] + amt[3]);
    
}

LL solve(int n){
    LL ret = 0;
    build();

    for(int i = 4; i<=n ; i++){
        LL a = accum[i-3] + amt[i-1] + amt[i];
        for(int j = 4 ; j<=i ; j++)
            a = max(a, accum[i-j] + amt[i-1] + amt[i]);
        
        LL b = accum[i-2] + amt[i];
        for(int j = 3 ; j<=i ; j++)
            b = max(b, accum[i-j] + amt[i]);
        
        accum[i] = max(a, b);
    }
    
    for(int i = 1 ; i <= n ; i++){
        //cout<<accum[i]<<" ";
        ret = max(ret, accum[i]);
    }
    return ret;
}


int main(int argc, const char * argv[]) {
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}

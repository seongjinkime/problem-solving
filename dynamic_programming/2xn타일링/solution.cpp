//
//  main.cpp
//  11726_2xn타일링
//
//  Created by Kim Seong Jin on 02/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;
int d[1001];

int dp(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    if(d[n]>0)return d[n];
    return d[n] = (dp(n-1) + dp(n-2))%10007;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    cout<<dp(n)<<endl;
    return 0;
}

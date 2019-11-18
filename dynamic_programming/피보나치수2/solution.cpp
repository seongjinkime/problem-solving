//
//  main.cpp
//  2748_피보나치수2
//
//  Created by Kim Seong Jin on 18/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define MAX 91

using namespace std;
typedef long long LL;
LL fibo[MAX];

LL solve(int n){
    if(n<3) return fibo[n];
    
    for(int i = 3 ; i <= n ; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[n];
}

void build(){
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
}

int main(int argc, const char * argv[]) {
    int n;
    build();
    
    cin>>n;
    cout<<solve(n)<<endl;
    
    return 0;
}

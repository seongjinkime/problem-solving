//
//  main.cpp
//  9020_골드바흐의추측
//
//  Created by Kim Seong Jin on 20/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <math.h>

#define MAX 10001

using namespace std;

int primes[MAX];

void init(){
    fill_n(primes, MAX, 1);
    primes[0] = primes[1] = 0;
    for(int i = 2 ; i<=sqrt(MAX) ; i++){
        if(primes[i]==0)
            continue;
        for(int j = i+i ; j < MAX ; j+=i){
            primes[j] = 0;
        }
    }
}

void solve(int num){
    int retA, retB;
    for(int a = 1 ; a <= num/2 ; a ++){
        int b = num - a;
        if(primes[a] && primes[b]){
            retA = a;
            retB = b;
        }
    }
    cout<<retA<<" "<<retB<<endl;
}

int main(int argc, const char * argv[]) {
    init();
    int n, num;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>num;
        solve(num);
    }
    return 0;
}

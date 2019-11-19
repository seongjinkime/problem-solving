//
//  main.cpp
//  1929_소수구하기
//
//  Created by Kim Seong Jin on 19/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <math.h>
#define MAX 1000001

using namespace std;

int primes[MAX];

void init(){
    int range = sqrt(MAX);
    
    fill_n(primes, MAX, 1);
    primes[0] = primes[1] = 0;
    
    for(int i = 2 ; i <= range ; i++){
        if(primes[i] == 0){
            continue;
        }
        for(int j = i+i ; j < MAX ; j+=i){
            primes[j] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    init();
    int start, end;
    
    cin>>start>>end;
    for(int i = start ; i <= end ; i++){
        if(primes[i] == true){
            printf("%d\n", i);
        }
    }
    
    return 0;
}

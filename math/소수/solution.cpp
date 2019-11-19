//
//  main.cpp
//  2581_소수
//
//  Created by Kim Seong Jin on 19/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <math.h>
#define MAX 10001

using namespace std;

int primes [MAX];

void init(){
    int range = sqrt(MAX);
    fill_n(primes, MAX, 1);
    primes[0] = primes[1] = 0;
    
    for(int i = 2 ; i <= range ; i++){
        if(primes[i] == 0)
            continue;
        for(int j = i+i; j< MAX ; j+=i){
            primes[j] = 0;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int start, end;
    int minimum, sum, cnt;
    
    cnt = 0;
    minimum = MAX;
    sum = 0;
    init();
    cin>>start>>end;
    
    for(int i = start ; i <= end ; i++){
        if(primes[i] == true){
            minimum = min(minimum, i);
            sum += i;
            cnt ++;
        }
    }
    
    if(cnt > 0){
        printf("%d\n%d", sum, minimum);
    }else{
        printf("-1");
    }
    
    
    return 0;
}
//cnt 강화, 0, 1 => 소수 아님

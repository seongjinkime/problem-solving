//
//  main.cpp
//  4948_베르트랑공준
//
//  Created by Kim Seong Jin on 20/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <math.h>
#define MAX 123456 * 2 + 1

using namespace std;
int prime[MAX];

void init(){
    fill_n(prime, MAX, 1);
    prime[0] = prime[1] = 0;
    
    for(int i = 2 ; i <= sqrt(MAX) ; i++){
        if(prime[i] == 0)
            continue;
        for(int j = i + i ; j < MAX ; j+=i){
            prime[j] = 0;
        }
    }
}

void solve(int start){
    int end;
    int cnt = 0;
    
    end = start * 2;
    
    for(int num = start + 1 ; num <= end ; num++){
        if(prime[num])
            cnt++;
    }
    cout<<cnt<<endl;
}


int main(int argc, const char * argv[]) {
    int num;
    init();
    num = 1;
    
    while(true){
        cin>>num;
        if(num ==0)
            break;
        solve(num);
    }
    
    return 0;
}

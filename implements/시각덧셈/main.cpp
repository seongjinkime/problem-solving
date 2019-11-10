//
//  main.cpp
//  1976_시각덧셈
//
//  Created by Kim Seong Jin on 01/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;

void solution(int t){
    int h, m;
    int h1, m1, h2, m2;
    
    h = 0;
    cin>>h1>>m1>>h2>>m2;
    
    m = m1 + m2;
    if(m>59){
        m -= 60;
        h++;
    }
    h += h1 + h2;
    if(h>12){
        h-=12;
    }
    printf("#%d %d %d\n", t, h, m);
        
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        solution(i);
    }
    return 0;
}

//
//  main.cpp
//  11653_소인수분해
//
//  Created by Kim Seong Jin on 29/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int num, factor;
    cin>>num;
    
    while(num!=1){
        factor = 2;
        while(num%factor != 0){
            factor++;
        }
        cout<<factor<<endl;
        num/=factor;
    }
    return 0;
}

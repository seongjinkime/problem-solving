//
//  main.cpp
//  5543_상근날드
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 2001
using namespace std;

int main(int argc, const char * argv[]) {
    int burger, vebrage, price;
    int ret;
    
    burger = vebrage = MAX;
    for(int i = 0 ; i < 3 ; i++){
        cin>>price;
        burger = min(burger, price);
    }
    for(int i = 0 ; i <  2 ; i++){
        cin>>price;
        vebrage = min(vebrage, price);
    }
    
    ret = burger + vebrage - 50;
    cout<<ret<<endl;
    return 0;
}

//
//  main.cpp
//  4153_직각삼각형
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

bool react(int a, int b, int c){
    return pow(a, 2) == pow(b, 2) + pow(c, 2);
}

int main(int argc, const char * argv[]) {
    int a, b, c;
    
    while (true) {
        cin>>a>>b>>c;
        if(a==0 && b == 0 && c == 0)
            break;
        if(react(a, b, c) || react(b, a, c) || react(c, a, b))
            cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;
    }
    
    return 0;
}

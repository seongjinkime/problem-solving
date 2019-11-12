//
//  main.cpp
//  1940_가랏!RC카!
//
//  Created by Kim Seong Jin on 12/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct _CAR{
    int speed;
    int move;
    _CAR(){speed = 0; move = 0;}
}car;


void solve(int t, int n){
    car c = car();
    //cmd is command type, ns is new speed
    int cmd, ns;
    
    for(int i = 0 ; i < n ; i++){
        cin>>cmd;
        if(cmd==1){
            cin>>ns;
            c.speed += ns;
        }else if(cmd==2){
            cin>>ns;
            if(c.speed-ns > 0){
                c.speed -= ns;
            }else{
                c.speed = 0;
            }
        }
        
        c.move += c.speed;
    }
    printf("#%d %d\n", t, c.move);
}

int main(int argc, const char * argv[]) {
    int t, n;
    cin>>t;
    for(int i = 1; i<=t ; i++){
        cin>>n;
        solve(i, n);
    }
    return 0;
}

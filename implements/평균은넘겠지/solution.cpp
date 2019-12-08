//
//  main.cpp
//  4344_평균은넘겠지
//
//  Created by Kim Seong Jin on 2019. 11. 28..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
void solve(){
    double n;
    cin>>n;
    
    int score[1001];
    int total = 0;
    double cnt=0;
    double ave, rate;
    
    for(int i = 0 ; i < n ; i++){
        cin>>score[i];
        total += score[i];
    }
    ave = total / n;
    
    for(int i = 0 ; i < n ; i++){
        if(score[i] > ave){
            cnt++;
        }
    }
    cout<<fixed;
    cout.precision(3);
    rate = (cnt/n) * 100;
    //rate = ceil(rate * 1000) / 1000;
    cout<<rate<<"%"<<endl;
    
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 0 ; i <  t; i++)
        solve();
    return 0;
}

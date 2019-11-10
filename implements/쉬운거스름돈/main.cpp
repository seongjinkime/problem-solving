//
//  main.cpp
//  1970_쉬운거스름돈
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define n 8

using namespace std;

int money [] {50000, 10000, 5000, 1000, 500, 100, 50, 10};
int coins [n];

void solution(int t){
    int total;
    cin>>total;
    for(int i = 0 ; i < n ; i++){
        coins[i] = total/money[i];
        total -= money[i] * coins[i];
    }
    cout<<"#"<<t<<endl;
    for(int c : coins)cout<<c<<" ";
    cout<<endl;
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 1 ; i<=t ; i++){
        solution(i);
    }
    return 0;
}

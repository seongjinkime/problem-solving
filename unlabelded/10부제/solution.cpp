//
//  main.cpp
//  10797_10부제
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int num, cnt;
    cin>>n;
    cnt = 0;
    for(int i = 0 ; i < 5 ; i++){
        cin>>num;
        if(num==n)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

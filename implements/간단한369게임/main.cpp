//
//  main.cpp
//  1926_간단한369게임
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int getClap(int n){
    string str = to_string(n);
    int clap = 0;
    clap += count(str.begin(), str.end(), '3');
    clap += count(str.begin(), str.end(), '6');
    clap += count(str.begin(), str.end(), '9');
    return clap;
    
}

int main(int argc, const char * argv[]) {
    int n, clap;
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        clap = getClap(i);
        if(clap>0){
            for(int cnt = 0 ; cnt < clap ; cnt++){
                cout<<"-";
            }
        }else{
            cout<<i;
        }
        cout<<" ";
    }
    
    return 0;
}

//
//  main.cpp
//  1065_한수
//
//  Created by Kim Seong Jin on 30/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>

using namespace std;

int getHan(int n){
    
    if(n<100)
        return n;
    
    int han = 99;
    int digit[3];
    for(int i = 100 ; i<=n && i<1000 ; i++){
        digit[0] = (i/100)%10;
        digit[1] = (i/10)%10;
        digit[2] = i%10;
        if(digit[0]-digit[1] == digit[1] - digit[2]){
            han++;
        }
    }
    return han;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    cout<<getHan(n);
    
    return 0;
}

//
//  main.cpp
//  1748_수이어쓰기1
//
//  Created by Kim Seong Jin on 06/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int digit = 1;
    int start = 1;
    int end = 9;
    int ret=0;
    int n;
    cin>>n;
    
    while(true){
        //cout<<start<<" "<<end<<endl;

        if(n>end){
            ret += (end-start+1)*digit;
            start*=10;
            end = (end*10)+9;
            digit++;
        }else{
            ret += (n-start+1)*digit;
            break;
        }
    }
    cout<<ret<<endl;
    return 0;
}

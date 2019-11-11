//
//  main.cpp
//  1193_분수찾기
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int sum, num, a, b;
    sum=1;
    num = 2;
    while(sum<n){
        sum += num;
        num++;
    }
    a = num-1-(sum-n);
    b = num-a;
    if(num%2 == 0){
        cout<<b<<"/"<<a<<endl;
    }else{
        cout<<a<<"/"<<b<<endl;
    }
    
    return 0;
}

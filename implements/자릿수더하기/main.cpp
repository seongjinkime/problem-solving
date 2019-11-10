//
//  main.cpp
//  2058_자릿수더하기
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int num;
    int digitSum = 0;
    cin>>num;
    while (num>0) {
        digitSum += num%10;
        num/=10;
    }
    cout<<digitSum<<endl;
    return 0;
}

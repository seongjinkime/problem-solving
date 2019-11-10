//
//  main.cpp
//  2068_최대수구하기
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int t, num, max;
    cin>>t;
    for(int cnt = 0 ; cnt<t ; cnt++){
        max = 0;
        for(int i = 0 ; i < 10 ; i++){
            cin>>num;
            if(num>max){
                max = num;
            }
        }
        printf("#%d %d\n", cnt+1, max);
    }
    return 0;
}

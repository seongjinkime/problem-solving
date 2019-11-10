//
//  main.cpp
//  1986_지그재그숫자
//
//  Created by Kim Seong Jin on 01/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>

using namespace std;

void solution(int t, int n){
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        if(i%2==0){
            sum-=i;
        }else{
            sum+=i;
        }
    }
    printf("#%d %d\n", t, sum);
}

int main(int argc, const char * argv[]) {
    int t, n;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
        cin>>n;
        solution(i, n);
    }
    
    return 0;
}

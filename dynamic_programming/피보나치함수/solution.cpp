//
//  main.cpp
//  1003_피보나치함수
//
//  Created by Kim Seong Jin on 20/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 41

using namespace std;

int zeros [MAX] = {1, 0};
int ones [MAX] = {0, 1};

void solve(int num){
    for(int i = 2 ; i<= num ; i++){
        zeros[i] = zeros[i-1] + zeros[i-2];
        ones[i] = ones[i-1] + ones[i-2];
    }
    cout<<zeros[num] <<" "<<ones[num]<<endl;
}

int fibo(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        int a = n-1;
        int b = n-2;
        return (fibo(a) + fibo(b));
    }
}

int main(int argc, const char * argv[]) {
    int n, num;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>num;
        solve(num);
    }
    return 0;
}

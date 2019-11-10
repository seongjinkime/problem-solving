//
//  main.cpp
//  2072_홀수만더하기
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>

using namespace std;

void solution(int t){
    int total = 0;
    int num;

    for(int i = 0 ; i < 10 ; i++){
        cin>>num;
        total += num%2 == 0 ? 0 : num;
    }
    printf("#%d %d\n", t, total);
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++)
        solution(i+1);
    
    return 0;
}

//
//  main.cpp
//  1984_중간평균값구하기
//
//  Created by Kim Seong Jin on 01/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <cmath>
#define MAX 10001
using namespace std;
int arr[10];
void solution(int t){
    int minN = MAX;
    int maxN = 0;
    double sum = 0;
    int ave;
    
    for(int i = 0 ; i < 10 ; i++){
        cin>>arr[i];
        minN = min(minN, arr[i]);
        maxN = max(maxN, arr[i]);
        sum += arr[i];
    }
    sum -= minN + maxN;
    ave = (int) floor((sum/8.0) + 0.5);
    printf("#%d %d\n", t, ave);
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 1 ; i<= t ; i++){
        solution(i);
    }
    return 0;
}

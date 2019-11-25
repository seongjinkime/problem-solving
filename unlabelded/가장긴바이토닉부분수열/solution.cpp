//
//  main.cpp
//  11054_가장긴바이토닉부분수열
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 1001
using namespace std;

int lis[MAX];
int lds[MAX+1];
int nums[MAX];

int n;

void buildLis(){
    for(int i = 1 ; i<=n ; i++){
        int maxCnt = 0;
        for(int j = 0 ; j<i ; j++){
            if(nums[i]>nums[j]){
                maxCnt = max(maxCnt, lis[j]);
            }
        }
        lis[i] = maxCnt+1;
    }
}

void buildLds(){
    for(int i = n ; i>=0 ; i--){
        int maxCnt = 0;
        for(int j = n+1 ; j>i ; j--){
            if(nums[i] > nums[j]){
                maxCnt = max(maxCnt, lds[j]);
            }
        }
        lds[i] = maxCnt+1;
    }
}

void build(){
    for(int i = 1 ; i<= n ; i++){
        cin>>nums[i];
    }
}


int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    //create long increment sequence
    buildLis();
    //create long decrease  sequence
    //lds();
    buildLds();
    int ret = 0;
    for(int i = 1 ; i<=n ; i++){
        int len = (lis[i] + lds[i]) - 1;
        ret = max(ret, len);
    }
    cout<<ret<<endl;
    return 0;
}

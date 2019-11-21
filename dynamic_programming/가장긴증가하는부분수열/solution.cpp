//
//  main.cpp
//  11053_가장긴증가하는부분수열_retry
//
//  Created by Kim Seong Jin on 21/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 1001
using namespace std;

int nums[MAX];
int permutation[MAX];
int n;
int solve(){
    int ret = 0;
    for(int i = 1 ; i<=n ; i++){
        int maxCnt = 0;
        for(int j = 0 ; j < i ; j++){
            if(nums[i]>nums[j]){
                maxCnt = max(maxCnt, permutation[j]);
            }
        }
        permutation[i] = maxCnt+1;
        ret = max(ret, permutation[i]);
    }
    return ret;
}

void build(){
    for(int i = 1 ; i<= n ; i++){
        cin>>nums[i];
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    cout<<solve()<<endl;
    return 0;
}

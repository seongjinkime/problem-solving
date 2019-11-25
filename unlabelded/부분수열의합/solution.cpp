//
//  main.cpp
//  1182_부분수열의합
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 21
using namespace std;
vector<int>nums;
vector<bool>selected;
int n, s;
int ret;

void comb(int here, int cnt, int digit){
    if(cnt==digit){
        int sum = 0;
        for(int i = 0 ; i < selected.size() ; i++){
            if(selected[i]){
                sum+=nums[i];
            }
        }
        if(sum==s){
            ret++;
        }
        return;
    }
    for(int there = here ; there < n ; there++){
        if(!selected[there]){
            selected[there] = true;
            comb(there, cnt+1, digit);
            selected[there] = false;
        }
    }
}

void build(){
    ret = 0;
    selected = vector<bool>(n, false);
    nums = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
}


int main(int argc, const char * argv[]) {
    cin>>n>>s;
    build();
    for(int i = 1 ; i <= n ; i++){
        comb(0, 0, i);
    }
    cout<<ret<<endl;
    
    return 0;
}

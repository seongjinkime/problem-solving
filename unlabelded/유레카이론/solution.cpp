//
//  main.cpp
//  10448_유레카이론
//
//  Created by Kim Seong Jin on 04/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;
int gauss[MAX];
int k;
bool triangle;

void init(){
    for(int i = 1; i <= 1000 ; i++){
        gauss[i] = i*(i+1) / 2;
    }
}

void dfs(int cnt, int sum, int idx){
    if(cnt==3){
        if(sum == k)
            triangle = true;
        return;
    }
    for(int t = 1 ; t<= 1000 ; t++){
        if(sum + gauss[t] <= k && !triangle){
            dfs(cnt+1, sum+gauss[t], t);
        }
    }
}

void solve(){
    
    triangle = false;
    cin>>k;
    //cout<<gauss[k]<<endl;
    dfs(0, 0, 1);
    cout<<triangle<<endl;
}
int main(int argc, const char * argv[]) {
    init();
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        solve();
    }
    return 0;
}

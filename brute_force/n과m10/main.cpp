//
//  main.cpp
//  15664_n과m10
//
//  Created by Kim Seong Jin on 09/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define MAX 9
using namespace std;
vector<int> nums;
vector<bool>selected;
vector<int>permutaion;
int n,m;
set<string> s;

void print(){
    string sNum;
    for(int i = 0 ; i < permutaion.size() ; i++){
        sNum += permutaion[i]+'0';
        sNum += ' ';
    }
    if(s.count(sNum)==0){
        printf("%s\n", sNum.c_str());
        s.insert(sNum);
    }
    
}

void dfs(int cnt){
    if(cnt==m){
        print();
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(!selected[i]){
            if(!permutaion.empty() && nums[i]<permutaion.back())
                continue;
            selected[i]=true;
            permutaion.push_back(nums[i]);
            dfs(cnt+1);
            permutaion.pop_back();
            selected[i]=false;
        }
    }
}

void build(){
    nums = vector<int>(n);
    selected = vector<bool>(n);
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
}


int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    dfs(0);
    return 0;
}

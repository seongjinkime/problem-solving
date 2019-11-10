//
//  main.cpp
//  15655_n과m6
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>nums;
vector<bool>selected;
int n,m;

void print(){
    for(int i = 0 ; i < nums.size() ; i++){
        if(selected[i])
            printf("%d ", nums[i]);
    }
    printf("\n");
}
void combination(int here, int cnt){
    if(cnt==m){
        print();
        return;
    }
    for(int there = here ; there<n ; there++){
        if(!selected[there]){
            selected[there]=true;
            combination(there, cnt+1);
            selected[there]=false;
        }
    }
}

void build(){
    selected = vector<bool>(n);
    nums = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    build();
    combination(0, 0);
    return 0;
}

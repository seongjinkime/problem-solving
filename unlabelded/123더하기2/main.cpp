//
//  main.cpp
//  12101_123더하기2
//
//  Created by Kim Seong Jin on 16/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 12
#include <algorithm>

using namespace std;
int arr[12];
vector<vector<int>> lists;
int n, k;

bool comp(vector<int> a, vector<int> b){
    int idxA, idxB;
    idxA = idxB = 0;
    
    while(a[idxA] == b[idxA]){
        idxA++;
        idxB++;
    }
    
    return a[idxA]<b[idxB];
}

int find(int num, vector<int> nums){
    int ret = 0;
    
    if(num == n){
        lists.push_back(nums);
        return true;
    }
    if(num > n ){
        return false;
    }
    
    for(int i = 1 ; i <= 3 ; i++){
        vector<int> next = nums;
        next.push_back(i);
        ret += find(num+i, next);
    }
    return ret;
}

int main(int argc, const char * argv[]) {

    fill_n(arr, MAX, 0);
    cin>>n>>k;
    find(0, {});
    
    sort(lists.begin(), lists.end(), comp);
 
    if(lists.size() < k){
        cout<<-1<<endl;
        return 0;
    }
    
    vector<int> nums = lists[k-1];
    
    for(int i = 0 ; i < nums.size() ; i++){
        cout<<nums[i];
        if(i != nums.size()-1){
            cout<<"+";
        }
    }
    cout<<endl;
    
    
    return 0;
}

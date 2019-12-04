//
//  main.cpp
//  14888_연산자끼워넣기
//
//  Created by Kim Seong Jin on 04/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#define MAX 1000000001
#define MIN -1000000001
using namespace std;

map<int, char> op;
vector<int>permutation;
vector<bool> selected;
vector<int>nums;
long long minimum, maximum;
int n, opNum;

long long cal(long long a, long long b, char c){
    switch (c) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
    return -1;
}

void sum(){
    long long num = nums[0];
    int idx = 0;
    for(int i = 1 ; i<nums.size() ; i++, idx++){
        //cout<<permutation[idx]<<" ";
        //cout<<permutation[i]<<" ";
        //cout<<num<<" " << op[permutation[idx]] << " " << nums[i]<<" | ";
        num = cal(num, nums[i], op[permutation[idx]]);
        
    }
    //cout<<"= " <<num<<endl;
    minimum = min(minimum, num);
    maximum = max(maximum, num);
}

void genPerm(int cnt){
    if(cnt == opNum){
        sum();
        return;
    }
    
    for(int i = 0 ; i < opNum ; i++){
        if(!selected[i]){
            selected[i] = true;
            permutation.push_back(i);
            genPerm(cnt+1);
            permutation.pop_back();
            selected[i] = false;
        }
    }
}

void build(){
    char opType[4] {'+', '-', '*', '/'};
    int cnt, idx;
    
    opNum = n-1;
    minimum = MAX;
    maximum = MIN;
    idx = 0;
    nums = vector<int>(n, 0);
    selected = vector<bool>(n, false);
    
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    
    for(int i = 0 ; i < 4 ; i++){
        cin>>cnt;
        //cout<<cnt<<endl;
        for(int j = 0 ; j < cnt ; j++){
            op[idx] = opType[i];
            idx++;
        }
    }

}


int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    genPerm(0);
    cout<<maximum<<endl;
    cout<<minimum<<endl;
    
    //cout<<-7/2<<endl;
    return 0;
}

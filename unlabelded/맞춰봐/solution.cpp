//
//  main.cpp
//  1248_맞춰봐
//
//  Created by Kim Seong Jin on 26/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#define MAX 11

using namespace std;
vector<bool> selected;
vector<int> nums;
vector<int>permutation;
int n;
long long cnt;
string op;

bool pass(int idx, int num){
    //cout<<idx<<" : "<<num<<endl;
    if(op[idx] == '-'){
        return num < 0;
    }else if(op[idx] == '+'){
        return num > 0;
    }else if (op[idx] == '0'){
        return num == 0;
    }
    return false;
}

bool isAns(){
    int idx = 0;
    for(int i = 0 ; i < n ; i++){
        int sum = permutation[i];
        //cout<<sum<<" ";
        if(!pass(idx, sum)){
            return false;
        }
        idx++;
        for(int j = i+1 ; j < n ; j++){
            sum += permutation[j];
            //cout<<sum<<" ";
            
            if(!pass(idx, sum)){
                return false;
            }
            //cout<<op[idx]<<" ";
            idx++;
        }
        //cout<<endl;
    }
    return true;
}

void perm(int cnt){
    if(cnt==n){
        cnt++;
        if(isAns()){
            for(int i = 0 ; i < permutation.size() ; i++){
                printf("%d ", permutation[i]);
            }
            cout<<endl;
            exit(0);
        }
        
        return;
    }
    
    for(int i = 0; i < nums.size() ; i ++){
        if(!selected[i]){
            selected[i] = true;
            permutation.push_back(nums[i]);
            perm(cnt+1);
            permutation.pop_back();
            selected[i] = false;
        }
    }
}

void build(){
    nums = vector<int>(21);
    selected = vector<bool>(21, false);
    int num = -10;
    for(int i = 0; i < 21 ; i++){
        nums[i] = num;
        num++;
    }
}



int main(int argc, const char * argv[]) {
    cnt = 0;
    cin>>n;
    //op = "-+0++++--+";
    cin>>op;
    build();
    //permutation = vector<int>{-2, 5, -3, 1};
    //cout<<isAns()<<endl;
    perm(0);
    cout<<cnt<<endl;
    //cout<<isAns()<<endl;
    return 0;
}

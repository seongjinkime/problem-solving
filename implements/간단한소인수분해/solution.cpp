//
//  main.cpp
//  1945_간단한소인수분해
//
//  Created by Kim Seong Jin on 12/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define MAX 5

using namespace std;

int nums[5] {2,3,5,7,11};
int cnt[5] {0,0,0,0,0};
int cursor;

void init(){
    cursor = 0;
    for(int i = 0 ; i < 5 ; i++)
        cnt[i] = 0;
}

void factorization(int n){
    init();
    int num = nums[cursor];
    while(n!=0){
        if(n%num == 0){
            cnt[cursor]++;
            n /= num;
        }else{
            if(cursor+1 < MAX){
                num = nums[++cursor];
                continue;
            }else{
                break;
            }
        }
    }
}

void print(int t){
    cout<<"#"<<t<<" ";
    for(int c : cnt) cout<<c<<" ";
    cout<<endl;
}

void solve(int t){
    int n;
    
    cin>>n;
    factorization(n);
    print(t);
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
        solve(i);
    }
    
    return 0;
}

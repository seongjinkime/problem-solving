//
//  main.cpp
//  15652_n과m4
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 9

using namespace std;

bool selected[MAX];
int arr[MAX];
vector<int>num;

int n, m;
void print(){
    for(int i = 0 ; i < num.size() ; i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

void permutation(int cnt){
    if(cnt==m){
        print();
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(!num.empty() && arr[i] < num.back())
            continue;
        
        selected[i]=true;
        num.push_back(arr[i]);
        permutation(cnt+1);
        num.pop_back();
        selected[i]=false;
    }
}


void build(){
    for(int i = 1 ; i<=n ; i++){
        arr[i-1] = i;
    }
}


int main(int argc, const char * argv[]) {
    cin>>n>>m;

    build();
    permutation(0);
    return 0;
}

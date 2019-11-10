//
//  main.cpp
//  15650_n과m2
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define MAX 9

using namespace std;

bool selected[MAX];
int arr[MAX];
int n, m;
void print(){
    for(int i = 0 ; i < MAX ; i++){
        if(selected[i])
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void combination(int here, int cnt){
    if(cnt==m){
        print();
        return;
    }
    for(int there = here ; there < n ; there++){
        if(!selected[there]){
            selected[there]=true;
            combination(there, cnt+1);
            selected[there]=false;
        }
    }
}

void build(){
    for(int i = 1 ; i <= n ; i++){
        arr[i-1]=i;
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    combination(0, 0);
    return 0;
}

//
//  main.cpp
//  15651_n과m3
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 9

using namespace std;

int arr[MAX];
bool visit[MAX];
vector<int>num;
int n,m;
void print(){
    for(int i = 0 ; i < num.size() ; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}

void dfs(int cnt){
    if(cnt==m){
        print();
        return;
    }
    for(int i = 0 ; i < n ; i++){
        visit[i]=true;
        num.push_back(arr[i]);
        dfs(cnt+1);
        num.pop_back();
        visit[i]=false;
    }
}

void build(){
    for(int i = 1 ; i <= n ; i++){
        arr[i-1] = i;
    }
}


int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    build();
    dfs(0);
    return 0;
}

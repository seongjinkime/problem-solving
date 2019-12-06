//
//  main.cpp
//  14391_종이조각
//
//  Created by Kim Seong Jin on 06/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 5
using namespace std;
int table[MAX][MAX];
bool selected[MAX][MAX];
int n, m;
int ret;

int sumOfHorizon(){
    int num, sum;
    sum = 0;
    for(int y = 0 ; y < n ; y++){
        num = 0;
        for(int x = 0 ; x < m ; x++){
            if(selected[y][x]==1){
                num = (num * 10) + table[y][x];
            }else{
                sum += num;
                num = 0;
            }
        }
        sum += num;
    }
    return sum;
}

int sumOfVertical(){
    int num, sum;
    sum = 0;
    for(int x = 0 ; x < m ; x++){
        num = 0;
        for(int y = 0 ; y < n ; y++){
            if(selected[y][x]==0){
                num = (num * 10) + table[y][x];
            }else{
                sum += num;
                num = 0;
            }
        }
        sum += num;
    }
    return sum;
}

void sum(){
    int sum;
    sum = sumOfHorizon() + sumOfVertical();
    ret = max(ret, sum);
}

void dfs(int y, int x){
    if(y >= n){
        sum();
        return;
    }
    
    if(x >= m){
        dfs(y+1, 0);
        return;
    }
    
    selected[y][x] = true;
    dfs(y, x+1);
    selected[y][x] = false;
    dfs(y, x+1);
    
}

void build(){
    ret = 0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            scanf("%1d", &table[y][x]);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    dfs(0, 0);
    cout<<ret<<endl;
    return 0;
}

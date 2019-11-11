//
//  main.cpp
//  1954_달팽이숫자
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>table;
int n;
int dy[4] {0,1,0,-1};
int dx[4] {1,0,-1,0};
int arrow;



bool isEmpty(int y, int x){
    return table[y][x] == 0;
}

void changeArrow(){
    arrow++;
}

void dfs(int y, int x){
    if (table[y][x] == (n*n)){
        //cout<<"CNT: "<<<<endl;
        return;
    }
    int ny = y + dy[arrow%4];
    int nx = x + dx[arrow%4];
    
    if(0<=nx && nx < n && 0<=ny && ny < n && isEmpty(ny, nx)){
        table[ny][nx] = table[y][x]+1;
        dfs(ny, nx);
        
    }else{
        changeArrow();
        dfs(y, x);
    }
}

void build(){
    table = vector<vector<int>>(n, vector<int>(n, 0));
    table[0][0] = 1;
    arrow = 0;
}

void print(){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cout<<table[y][x]<<" ";
        }
        cout<<endl;
    }
}

void solve(int t){
    printf("#%d\n", t);
    cin>>n;
    build();
    
    dfs(0,0);
    print();
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
        solve(i);
    }
    return 0;
}

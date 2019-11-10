//
//  main.cpp
//  3085_사탕게임
//
//  Created by Kim Seong Jin on 31/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>>table;

int maxOfTable(){
    
    int cnt, ret;
    ret = 0;
    cnt = 1;
    
    //check per row
    for(int y = 0 ; y < table.size() ; y++){
        int n = table[y].size()-1;
        cnt = 1;
        for(int x = 0 ; x<n ; x++){
            if(table[y][x] == table[y][x+1]){
                cnt++;
            }else{
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }
    
    
     //check per col
    for(int x = 0 ; x < table[0].size() ; x++){
        int n = table.size()-1;
        cnt = 1;
        for(int y = 0 ; y<n ; y++){
            if(table[y][x] == table[y+1][x]){
                cnt++;
            }else{
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }
     
    return ret;
    
}


void build(int n){
    table = vector<vector<char>>(n, vector<char>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>table[i][j];
        }
    }
}

int solution(int n){
    int candy = 0;
    build(n);
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            if(x+1<n){
                swap(table[y][x], table[y][x+1]);
                candy = max(candy, maxOfTable());
                swap(table[y][x], table[y][x+1]);
            }
            if(y+1<n){
                swap(table[y][x], table[y+1][x]);
                candy = max(candy, maxOfTable());
                swap(table[y][x], table[y+1][x]);
            }
        }
    }
    return candy;
}


int main(void){
    int n;
    cin>>n;
    cout<<solution(n)<<endl;
}

/*
5
YCPZY
CYZZP
CCPPP
YCYZC
CPPZZ
 */
 

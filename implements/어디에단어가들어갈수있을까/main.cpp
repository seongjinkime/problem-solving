//
//  main.cpp
//  1979_어디에단어가들어갈수있을까
//
//  Created by Kim Seong Jin on 01/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> table;



void build(int n){
    table = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>table[i][j];
        }
    }

}

void solution(int t, int n, int k){
    build(n);
    int possible = 0;
    int cnt = 0;
    
    for(int y = 0 ; y < n ; y++){
        cnt = 0;
        for(int x = 0 ; x < n ; x++){
            if(table[y][x] == 1){
                cnt++;
            }else{
                if(cnt==k)
                    possible++;
                cnt = 0;
            }
        }
        if(cnt==k)
            possible++;
    }
    
    for(int x = 0 ; x < n ; x++){
        cnt = 0;
        for(int y = 0 ; y < n ; y++){
            if(table[y][x] == 1){
                cnt++;
            }else{
                if(cnt==k)
                    possible++;
                cnt = 0;
            }
        }
        if(cnt==k)
            possible++;
    }
    printf("#%d %d", t, possible);
    
}

int main(int argc, const char * argv[]) {
    int t, n, k;
    cin>>t;
    
    for(int i = 1 ; i <= t ; i++){
        cin>>n>>k;
        solution(i, n, k);
    }
    
    return 0;
}

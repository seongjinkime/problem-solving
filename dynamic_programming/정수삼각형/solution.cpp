//
//  main.cpp
//  1932_정수삼각형
//
//  Created by Kim Seong Jin on 20/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 501

using namespace std;

int table[MAX][MAX];
int sum[MAX][MAX];
int h;

void print(){
    for(int y = 1 ; y <= h ; y++){
        for(int x = 1 ; x <= y ; x++){
            cout<<sum[y][x]<<" ";
        }
        cout<<endl;
    }
}

void build(){
    for(int y = 1 ; y <= h ; y++){
        for(int x = 1 ; x <= y ; x++){
            cin>>table[y][x];
        }
    }
}

void setSum(){
    sum[1][1] = table[1][1];
    for(int y = 2 ; y <= h ; y++){
        for(int x = 1 ; x <= y ; x++){
            if(x==1){
                sum[y][x] = sum[y-1][1] + table[y][1];
            }else if(x==y){
                sum[y][x] = sum[y-1][x-1] + table[y][x];
            }else{
                sum[y][x] = max(sum[y-1][x-1], sum[y-1][x]) + table[y][x];
            }
            
        }
    }
}

void solve(){
    setSum();
    //print();
    //return ;
    int maximum = 0;
    for(int x = 1 ; x<=h ; x++){
        maximum = max(maximum, sum[h][x]);
    }
    cout<<maximum<<endl;
}

int main(int argc, const char * argv[]) {
    cin>>h;
    build();
    solve();
    
    return 0;
}

//
//  main.cpp
//  1974_수도쿠검증
//
//  Created by Kim Seong Jin on 01/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <set>
#define n 9

using namespace std;
int table[9][9];


bool totalUnique(){
    
    set<int> s;
    for(int y = 0 ; y < n ; y++){
        s.clear();
        for(int x = 0 ; x < n ; x++){
            if(s.count(table[y][x])>0)
                return false;
            else
                s.insert(table[y][x]);
        }
    }
    
    for(int x = 0 ; x < n ; x++){
        s.clear();
        for(int y = 0 ; y < n ; y++){
            if(s.count(table[y][x])>0)
                return false;
            else
                s.insert(table[y][x]);
        }
    }
    return true;
}

bool subUnique(int sy, int sx, int dy, int dx){
    set<int>s;
    for(int y = sy ; y<= dy ; y++){
        for(int x = sx ; x <= dx ; x++){
            if(s.count(table[y][x])>0)
                return false;
            else
                s.insert(table[y][x]);
        }
    }
    return true;
}

bool sudoku(){
    if(!totalUnique())
        return false;
    for(int y = 0 ; y < n ; y+=3){
        for(int x = 0 ; x<n ; x+=3){
            if(!subUnique(y, x, y+2, x+2))
                return false;
        }
    }
    return true;
}


void build(){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cin>>table[y][x];
        }
    }
}

void solution(int t){
    build();
    printf("#%d %d\n", t, sudoku());
}


int main(int argc, const char * argv[]) {
    int tNum;
    cin>>tNum;
    for(int t =1 ; t <= tNum ; t++){
        solution(t);
    }
    
    return 0;
}

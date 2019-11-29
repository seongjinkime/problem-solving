//
//  main.cpp
//  2580_스도쿠
//
//  Created by Kim Seong Jin on 2019. 11. 28..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int table[9][9];
typedef pair<int,int> pos;
vector<pos> tofill;


void print(){
    for(int y = 0 ; y < 9 ; y++){
        for(int x = 0 ; x < 9 ; x++){
            cout<<table[y][x]<<" ";
        }
        cout<<endl;
    }
}

bool isUniqueZone(int y1, int y2, int x1, int x2){
    int arr[10];
    fill_n(arr, 10, 0);
    for(int y = y1 ; y <= y2 ; y++){
        for(int x = x1 ; x <= x2 ; x++){
            if(table[y][x] == 0)
                continue;
            //cout<<table[y][x]<<endl;
            if(arr[table[y][x]]>0){
                return false;
            }
            arr[table[y][x]] += 1;
        }
    }
    return true;
}

bool uniqueInZone(int y, int x){
    
    if(0<=y && y <= 2){
        if(0<=x && x<=2)
            return isUniqueZone(0, 2, 0, 2);
        else if (3<=x && x <= 5)
            return isUniqueZone(0, 2, 3, 5);
        else if (6<=x && x <= 8)
            return isUniqueZone(0, 2, 6, 8);
    }
    
    if(3<=y && y <= 5){
        if(0<=x && x<=2)
            return isUniqueZone(3, 5, 0, 2);
        else if (3<=x && x <= 5)
            return isUniqueZone(3, 5, 3, 5);
        else if (6<=x && x <= 8)
            return isUniqueZone(3, 5, 6, 8);
    }
    
    if(6<=y && y <= 8){
        if(0<=x && x<=2)
            return isUniqueZone(6, 8, 0, 2);
        else if (3<=x && x <= 5)
            return isUniqueZone(6, 8, 3, 5);
        else if (6<=x && x <= 8)
            return isUniqueZone(6, 8, 6, 8);
    }
    
    return false;
}

bool uniqueRowAndCol(int sy, int sx){
    int arr[10];
    fill_n(arr, 10, 0);
    for(int y = 0 ; y < 9 ; y++){
        if(table[y][sx] == 0)
            continue;
        if(arr[table[y][sx]] > 0){
            return false;
        }
        arr[table[y][sx]] += 1;
    }
    fill_n(arr, 10, 0);
    for(int x = 0 ; x < 9 ; x++){
        if(table[sy][x] == 0)
            continue;
        if(arr[table[sy][x]] > 0){
            return false;
        }
        arr[table[sy][x]] += 1;
    }
    return true;
}

bool possible(int y, int x){
    //각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
    //cout<<uniqueRowAndCol(y, x)<<endl;
    if(!uniqueRowAndCol(y, x))
        return false;

    //굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
    if(!uniqueInZone(y, x)){
        return false;
    }
    
    return true;
}

void fill(int idx){
    if(idx == tofill.size()){
        print();
        exit(0);
    }
    int y = tofill[idx].first;
    int x = tofill[idx].second;
    
    for(int num = 1 ; num <= 9 ; num++){
        table[y][x] = num;
        //cout<<num<<endl;
        if(possible(y, x)){
            fill(idx+1);
        }
        table[y][x] = 0;
    }
}

void build(){
    for(int y = 0 ; y < 9 ; y++){
        for(int x = 0 ; x < 9 ; x++){
            cin>>table[y][x];
            if(table[y][x] == 0){
                tofill.push_back(pos(y,x));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    build();
    //cout<<uniqueRowAndCol(0, 0)<<endl;
    fill(0);
    //cout<<uniqueInZone(0, 0)<<endl;
    return 0;
}

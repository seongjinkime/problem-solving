//
//  main.cpp
//  4963_섬의개수
//
//  Created by Kim Seong Jin on 05/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector< int>> table;
int w, h;
void bfs(int y, int x){
    table[y][x] = 0;
    if(x>0 && table[y][x-1] == 1)
        bfs(y, x-1);
    if(x<w-1 && table[y][x+1] == 1)
        bfs(y, x+1);
    if(y>0 && table[y-1][x] == 1)
        bfs(y-1, x);
    if(y<h-1 && table[y+1][x] == 1)
        bfs(y+1, x);
    if(x>0 && y>0 && table[y-1][x-1] == 1)
        bfs(y-1, x-1);
    if(x>0 && y < h-1 && table[y+1][x-1] == 1)
        bfs(y+1, x-1);
    if(x<w-1 && y > 0 && table[y-1][x+1] == 1 )
        bfs(y-1, x+1);
    if(x<w-1 && y < h-1 && table[y+1][x+1] == 1)
        bfs(y+1, x+1);
}

void build(int w, int h){
    table = vector<vector<int > >(h, vector<int>(w));
    for(int y = 0 ; y < h ; y++){
        for(int x = 0 ; x < w ; x++){
            cin>>table[y][x];
        }
    }
}

void solution(int w, int h){
    build(w, h);
    int cnt = 0;
    for(int y = 0 ; y < h ; y++){
        for(int x = 0 ; x < w ; x++){
            if(table[y][x]==1){
                bfs(y,x);
                cnt++;
            }
                
        }
    }
    cout<<cnt<<endl;
}


int main(){
    while(true){
        cin>>w>>h;
        if(w==0 && h==0)break;
        solution(w, h);
    }
    return 0;
}

//
//  main.cpp
//  1987_알파벳
//
//  Created by Kim Seong Jin on 05/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#define EMPTY ' '
#define MAX 21

using namespace std;
char table[MAX][MAX];

int dy[4] {-1, 1, 0 ,0};
int dx[4] {0, 0, -1 ,1};
int r, c;
int maxCnt;


bool isRange(int y, int x){
    return 0<=y && y < r && 0<=x && x < c;
}

bool visted(char c, string s){
    bool ret;
    if(s.find(c) == std::string::npos){
        ret = false;
    }else{
        ret = true;
    }
    return ret;
}

void dfs(int y, int x, int cnt, string str){
    
    maxCnt = max(maxCnt, cnt);
    
    for(int i = 0 ; i < 4 ; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(isRange(ny, nx) && table[ny][nx] != EMPTY){
            if(visted(table[ny][nx], str))
                continue;
            char tmp = table[ny][nx];
            string ns = str + table[ny][nx];
            table[ny][nx] = EMPTY;
            dfs(ny, nx, cnt+1, ns);
            table[ny][nx] = tmp;
            
        }
    }
    
}

void build(){
    maxCnt = 0;
    for(int y = 0 ; y < r ; y++){
        for(int x = 0 ; x < c ; x++)
            cin>>table[y][x];
    }
}

int main(int argc, const char * argv[]) {
    cin>>r>>c;
    build();
    char tmp = table[0][0];
    table[0][0] = EMPTY;
    dfs(0, 0, 1, string(1, tmp));
    cout<<maxCnt<<endl;
    return 0;
}

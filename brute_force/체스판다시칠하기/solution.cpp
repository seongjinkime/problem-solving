//
//  main.cpp
//  1018_체스판다시칠하기
//
//  Created by Kim Seong Jin on 18/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;
typedef vector<vector<char>> board;
board typeW, typeB, origin;
int n, m, out;


void initBoard(board& b, char start){
    char color[2] = {'W', 'B'};
    if(start == 'B')
        swap(color[0], color[1]);
    
    for(int y = 0 ; y < 8 ; y++){
        for(int x = 0 ; x < 8 ; x++){
            b[y][x] = color[x%2];
        }
        swap(color[0], color[1]);
    }
}

void build(){
    out = INF;
    typeW = typeB = board(8, vector<char>(8));
    origin = board(n, vector<char>(m));
    initBoard(typeW, 'W');
    initBoard(typeB, 'B');
    
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++)
            cin>>origin[y][x];
    }
}

void cost(int sy, int sx){
    int ny, nx;
    int cntTypeW, cntTypeB;
    
    cntTypeW = cntTypeB = 0;
    
    for(int y = 0 ; y < 8 ; y++){
        for(int x = 0 ; x < 8 ; x++){
            ny = y + sy;
            nx = x + sx;
            
            if(origin[ny][nx] != typeW[y][x])
                cntTypeW++;
            if(origin[ny][nx] != typeB[y][x])
                cntTypeB++;
        }
    }
    
    out = min(out, min(cntTypeW, cntTypeB));
}

void solve(){
    int rx, ry;// rangeX, rangeY
    rx = m - 8;
    ry = n - 8;
    
    for(int y = 0 ; y <= ry ; y++){
        for(int x = 0 ; x<= rx ; x++){
            cost(y, x);
        }
    }
}



int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    solve();
    cout<<out<<endl;
    return 0;
}

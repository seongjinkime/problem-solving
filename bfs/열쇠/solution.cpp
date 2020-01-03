//
//  main.cpp
//  9328_열쇠
//
//  Created by Kim Seong Jin on 05/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
#define EMPTY '.'
#define WALL '*'
#define DOCU '$'

using namespace std;

typedef pair<int, int> pos;
vector<vector<char>>table;
set<int> keys;
int dy[4]{-1, 1, 0, 0};
int dx[4]{0, 0, -1, 1};
int h, w;
int cnt;

bool inRange(int y, int x){
    return 0<=y && y < h && 0<=x && x<w;
}

bool bfs(){
    bool ret = false;
    int sy, sx, ny, nx;
    char ch;
    vector<vector<bool>> visted(h, vector<bool>(w, false));
    pos start(0, 0);
    queue<pos> q;
    q.push(start);
    visted[0][0] = true;
    
    while(!q.empty()){
        pos here = q.front();
        q.pop();
        sy = here.first;
        sx = here.second;
        
        for(int i = 0 ; i < 4 ; i++){
            ny = sy + dy[i];
            nx = sx + dx[i];
            if(!inRange(ny, nx) || visted[ny][nx] || table[ny][nx] == WALL)
                continue;
            
            ch = table[ny][nx];
            if(ch == DOCU){
                cnt++;
            }else if(ch != EMPTY){
                if(isupper(ch) && keys.count(ch-'A') == 0)
                    continue;
                else if(islower(ch)){
                    keys.insert(ch-'a');
                    ret = true;
                }
            }
            
            table[ny][nx] = EMPTY;
            visted[ny][nx] = true;
            q.push(pos(ny, nx));
            
        }
    }
    return ret;
}

void solve(){
    bool success = true;
    
    while (success) {
        success = bfs();
        //cout<<success<<endl;
    }
    cout<<cnt<<endl;
}

void build(){
    string kstr;
    keys.clear();
    cin>>h>>w;
    h+=2;
    w+=2;
    cnt = 0;
    table = vector<vector<char>>(h, vector<char>(w));
    
    for(int y = 1; y < h-1 ; y++){
        for(int x = 1 ; x < w-1 ; x++){
            cin>>table[y][x];
        }
    }
    for(int y = 0 ; y < h ; y++){
        table[y][0] = table[y][w-1] = EMPTY;
    }
    for(int x = 0 ; x < w ; x++){
        table[0][x] = table[h-1][x] = EMPTY;
    }
    
    cin>>kstr;
    if(kstr == "0")
        return;
    for(char k : kstr){
        keys.insert(k-'a');
    }
}

int main(int argc, const char * argv[]) {
    int t;

    cin>>t;
    for(int i = 0 ; i < t ; i++){
        build();
        solve();
    }
    

    return 0;
}

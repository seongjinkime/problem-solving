//
//  main.cpp
//  13460_구슬탈출2
//
//  Created by Kim Seong Jin on 10/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <vector>

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

#define WALL '#'
#define EMPTY '.'
#define DST 'O'

#define MAX_LEN 11
using namespace std;

typedef pair<int, int>pos;
typedef vector<pos> balls;
map<balls, int> path;
char table[MAX_LEN][MAX_LEN];
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, 1, -1};
int w, h;

int moveBall(pos& ball, int d){
    int cnt = 0;
    char ch = table[ball.first][ball.second];
    while(ch != WALL && ch != DST){
        ball.first = ball.first + dy[d];
        ball.second = ball.second + dx[d];
        cnt++;
    }
    return cnt;
}

void bfs(balls start){
    pos red, blue;
    int rMove, bMove;
    queue<balls>q;
    path[start] = 0;
    balls newBalls;
    
    while (!q.empty()) {
        balls current = q.front();
        red = current[0];
        blue = current[1];
        int dist = path[current];
        
        if(dist>10){
            cout<<"-1"<<endl;
            return;
        }
            
        for(int d = 0 ; d < 4 ; d++){
            rMove = moveBall(red, d);
            bMove = moveBall(blue, d);
            if(table[blue.first][blue.second] == DST)
                continue;
            if(table[blue.first][blue.second] == DST){
                cout<<dist+1<<endl;
                return;
            }
            
            if(red.first==blue.first && red.second == blue.second){
                if(rMove<bMove){
                    red.first -= dy[d];
                    red.second -= dx[d];
                }else{
                    blue.first -= dy[d];
                    blue.second -= dx[d];
                }
            }
            
            newBalls = {red, blue};
            if(path.count(newBalls)==0){
                path[newBalls] = dist+1;
                q.push(newBalls);
            }
                
            
        }
    }
    
}

balls build(){
    char ch;
    pos red, blue;
    for(int y = 0 ; y < h ; y++){
        for(int x = 0 ; x < w ; x++){
            cin>>ch;
            if(ch == 'R'){
                red = pos(y, x);
                ch = EMPTY;
            }else if(ch == 'B'){
                blue = pos(y, x);
                ch = EMPTY;
            }
            table[y][x] = ch;
        }
    }
    return {red, blue};
}

int main(int argc, const char * argv[]) {
    cin>>h>>w;
    balls start = build();
    bfs(start);

    return 0;
}

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
#define MAX 11

using namespace std;

typedef pair<int, int> pos;
typedef vector<pos> balls;
int dy[4] {-1, 1, 0, 0};
int dx[4] { 0, 0,-1, 1};
char table[MAX][MAX];
map<balls, int> dist;
pos hole;


bool vistied(balls b){
    return dist.count(b) > 0;
}

void moveBall(pos& ball, int& move, int y, int x){
    while(table[ball.first + y][ball.second + x] != '#'){ //!
        if(table[ball.first][ball.second] == 'O')
            break;
        ball.first += y;
        ball.second += x;
        move++;
    }
}

int bfs(balls b){
    queue<balls> q;
    q.push(b);
    dist[b] = 0;
    
    while(!q.empty()){
        balls current = q.front();
        q.pop();
        
        if(dist[current]>=10)
            return -1;

        for(int i = 0 ; i < 4 ; i++){
            //0 == Red, 1 == Blue
            pos nr = current[0];
            pos nb = current[1];
            int rDist = 0 ;
            int bDist = 0;
            
            moveBall(nr, rDist, dy[i], dx[i]);
            moveBall(nb, bDist, dy[i], dx[i]);
            
            //if fail
            if(nb == hole)
                continue;
            //if ok
            if(nr == hole)
                return dist[current]+1;
            
            if(nr == nb){
                if(rDist<bDist){
                    nb.first -= dy[i];
                    nb.second -= dx[i];
                }else{
                    nr.first -= dy[i];
                    nr.second -= dx[i];
                }
            }
  
            balls nset = balls{nr, nb};//!
            if(vistied(nset)) continue;
            
            dist[nset] = dist[current]+1;//!
            q.push(nset);
        }
    }
    return -1;
}

balls build(int w, int h){
    balls ret = vector<pos>(2);
    char ch;
    
    for(int y = 0 ; y < h ; y++){
        for(int x = 0 ; x < w ; x++){
            cin>>ch;
            if(ch == 'R'){
                ret[0] = pos(y, x);
            }else if(ch == 'B'){
                ret[1] = pos(y, x);
            }else if(ch == 'O'){
                hole = pos(y, x);
            }
            table[y][x] = ch;
        }
    }
    return ret;
}



int main(void){
    
    int w, h;
    cin>>h>>w;
    balls b = build(w, h);
    int mdist = bfs(b);
    cout<<mdist<<endl;
    
    return 0;
}

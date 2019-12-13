//
//  main.cpp
//  15558_점프게임
//
//  Created by Kim Seong Jin on 2019. 12. 13..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000+1

using namespace std;
struct walker{ int y, x, time;};
//udrl
int dy[4] {0, 0, -1, 1};
int dx[4] {-1, 1, 0, 0};
int map[2][MAX];
bool visited[2][MAX];
int n,k;

bool inRange(walker w){
    return 0<=w.y && w.y< 2 && w.time < w.x && w.x<n; //!
}

vector<walker> newWalkers(walker w){
    vector<walker> walkers;
    walkers.push_back({w.y, w.x+1, w.time});
    walkers.push_back({w.y, w.x-1, w.time});
    walkers.push_back({(w.y+1)%2, w.x+k, w.time});
    return walkers;
}

void solve(){
    queue<walker> q;
    q.push({0,0,0});
    visited[0][0] = true;
    bool succed = false;
    
    while(!q.empty() && !succed){
        walker current = q.front();
        q.pop();
        if(current.time >= n){ //!
            break;
        }
        for(walker nw : newWalkers(current)){
            if(nw.x >= n) //!
                succed = true;
            
            if(inRange(nw) && !visited[nw.y][nw.x]){
                if(map[nw.y][nw.x] == 1){
                    nw.time+=1;
                    visited[nw.y][nw.x] = true;
                    q.push(nw);
                }
                
    
            }
        }
    }
    cout<<succed<<endl;
}

void build(){
    for(int y = 0 ; y < 2 ; y++){
        for(int x = 0 ; x< n ; x++){
            scanf("%1d", &map[y][x]);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin>>n>>k;
    build();
    solve();
 
    //cout<<0<<endl;
    return 0;
}




/*
vector<pos> newPositions(pos p){
    vector<pos> ret(3);
    ret[0] = pos(p.first, p.second+1);
    ret[1] = pos(p.first, p.second-1);
    ret[2] = pos((p.first+1) % 2, p.second+k);
    return ret;
}

void move(int time, pos p){
 
    if(time>=n){
        return;
    }
    
    if(p.second>n){
        cout<<1<<endl;
        exit(0);
    }
    
    for(pos np : newPositions(p)){
        int ny = np.first;
        int nx = np.second;
        if(visited[ny][nx])
            continue;
        if(nx<n && map[ny][nx] == 0)
            continue;
        if(nx<time)
            continue;
        
        visited[ny][nx] = 1;
        move(time+1, np);
        visited[ny][nx] = 0;
    }
    
    //x+1
    //x-1
    //y+1 , x+k
    
    //!x<n && 0<=y&&y<2
    //map[ny][nx]==1
    //x >= time
    
    
    
}


void build(){
    for(int y = 0 ; y < 2 ; y++){
        for(int x = 0 ; x< n ; x++){
            scanf("%1d", &map[y][x]);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    build();
    move(0, pos(0,0));
    cout<<0<<endl;
    return 0;
}
*/












/*
typedef pair<int, pair<int, int>> pos;
int map[2][MAX];
int n,k;

bool inRange(int y, int x){
    return 0<= y && y < 2 && 0<=x;
}

bool isAvailable(pos p){
    int y = p.second.first;
    int x = p.second.second;
    int cnt = p.first;
    if(x<cnt)
        return false;
    if(x<n){
        return inRange(y, x) && map[y][x]==1;
    }else{
        return inRange(y, x);
    }
    
}

vector<pos> newPosisions(pos p){
    vector<pos> ret(3);
    int cnt = p.first;
    int y = p.second.first;
    int x = p.second.second;
    ret[0] = pos(cnt, make_pair(y, x+1));
    ret[1] = pos(cnt, make_pair(y, x-1));
    ret[2] = pos(cnt, make_pair((y+1)%2, x+k));
    return ret;
}

void removeRow(int x){
    map[0][x] = 0;
    map[1][x] = 0;
}

int tryGame(){
    int sy, sx;
    pos start(0, make_pair(0,0));
    queue<pos> q;
    q.push(start);
    int cnt = 0;
    while(!q.empty()){
        pos here = q.front();
        sy = here.second.first;
        sx = here.second.second;
        q.pop();
        
        if(sx > n){
            return 1;
        }
        if(here.first>n){
            continue;
        }
        //cout<<"CURRENT: "<<sy<<" , "<<sx<<endl;;
        for(pos np : newPosisions(here)){
            if(!isAvailable(np))
                continue;
            np.first+=1;
            //cout<<"NEW POS: "<<np.first<<" , "<<np.second<<endl;
            q.push(np);
        }
        
        //cout<<"T"<<endl;
        //removeRow(cnt++);
    }
    return 0;
}

void build(){
    for(int y = 0 ; y < 2 ; y++){
        for(int x = 0 ; x< n ; x++){
            scanf("%1d", &map[y][x]);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    build();
    cout<<tryGame()<<endl;
    return 0;
}
*/

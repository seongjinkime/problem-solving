//
//  main.cpp
//  14502_연구소
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 9
#define INF 987654321
using namespace std;
typedef pair<int, int> pos;
vector<vector<int>> map;
int visited[MAX][MAX];
vector<pos>virus;
//udrl
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, -1, 1};
int n, m;
int ret;

void print(vector<vector<int>> map){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cout<<map[y][x]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void count(vector<vector<int>> map){
    int cnt = 0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            if(map[y][x] == 0)
                cnt++;
        }
    }
    ret = max(ret, cnt);
}

void spread(){
    vector<vector<int>> table = map;
    vector<vector<int>> visited = vector<vector<int>>(n, vector<int>(m, 0));
    queue<pos> q;
    for(int i = 0 ; i < virus.size() ; i++){
        q.push(virus[i]);
        visited[virus[i].first][virus[i].second] = 1;
    }
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(0<=ny && ny<n && 0<=nx && nx<m && table[ny][nx] == 0 && visited[ny][nx] == 0){
                table[ny][nx] = 2;
                visited[ny][nx] = 1;
                q.push(pos(ny, nx));
            }
        }
    }
    //print(table);
    count(table);
    
}

void wallC(int y, int x){
    x += 1;
    while(y<n){
        while(x<m){
            if(map[y][x] == 1 || map[y][x] == 2){
                x++;
                continue;
            }
                
            map[y][x] = 1;
            spread();
            //print(map);
            
            map[y][x] = 0;
            x++;
            
        }
        x=0;
        y++;
    }
}


void wallB(int y, int x){
    x += 1;
    while(y<n){
        while(x<m){
            if(map[y][x] == 1 || map[y][x] == 2){
                x++;
                continue;
            }
            map[y][x] = 1;
            wallC(y, x);
            map[y][x] = 0;
            x++;
        }
        x=0;
        y++;
    }
}

void solve(){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            if(map[y][x] == 1 || map[y][x] == 2){
                continue;
            }
            
            map[y][x] = 1;
            wallB(y, x);
            map[y][x] = 0;
        }
    }
}
void init(){
    map = vector<vector<int>>(n, vector<int>(m));
    ret = 0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cin>>map[y][x];
            if(map[y][x] == 2){
                virus.push_back(pos(y, x));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    init();
    //cout<<endl;
    solve();
    cout<<ret<<endl;
    return 0;
}

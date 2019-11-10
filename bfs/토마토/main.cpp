//
//  main.cpp
//  7576_토마토
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

typedef struct _POINT{
    int x,y;
    _POINT(int _y, int _x){
        x = _x;
        y = _y;
    }
}point;

typedef vector<point> points;
//l r u d
int dy[4] {0, 0, -1, 1};
int dx[4] {-1, 1, 0, 0};

int table[MAX][MAX];
int uncomplete;
int n,m;

void bfs(points starts){
    queue<point>q;
    for(point p : starts){
        q.push(p);
    }
    while(!q.empty()){
        point here = q.front();
        q.pop();
        int sx = here.x;
        int sy = here.y;
        for(int i = 0 ; i < 4 ; i++){
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            
            if(0<=ny && ny<n && 0<=nx && nx<m && table[ny][nx] == 0){
                q.push(point(ny,nx));
                table[ny][nx] = table[sy][sx]+1;
                uncomplete--;
                if(uncomplete==0){
                    cout<<table[ny][nx]-1<<endl;
                    return;
                }
            }
        }
    }
    
    cout<<-1<<endl;
    
}

points build(){
    uncomplete=0;
    points starts;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cin>>table[y][x];
            if(table[y][x]==1)
                starts.push_back(point(y,x));
            else if(table[y][x]==0)
                uncomplete++;
        }
    }
    return starts;
}

int main(int argc, const char * argv[]) {
    cin>>m>>n;
    points starts = build();
    if(uncomplete==0){
        cout<<0<<endl;
        return 0;
    }
        
    bfs(starts);
    return 0;
}

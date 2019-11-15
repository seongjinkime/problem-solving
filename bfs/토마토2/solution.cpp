//
//  main.cpp
//  7569_토마토2
//
//  Created by Kim Seong Jin on 15/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

typedef struct _POS{
    int x, y, z;
    _POS(int _z, int _y, int _x){
        x = _x;
        y = _y;
        z = _z;
    }
}pos;

int table [MAX][MAX][MAX];
int m,n,h;
int uncomplete;
//udrl
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
int dz[2] = {1, -1};
void bfs(queue<pos> q){
    int cz, cy, cx;
    int nz, ny, nx;
    while(!q.empty()){
        pos here = q.front();
        q.pop();
        cx = here.x;
        cy = here.y;
        cz = here.z;
        
        for(int i = 0 ; i < 4 ; i++){
            ny = cy + dy[i];
            nx = cx + dx[i];
            if(0<=ny && ny < n && 0 <= nx && nx < m && table[cz][ny][nx] == 0){
                table[cz][ny][nx] = table[cz][cy][cx]+1;
                q.push(pos(cz, ny, nx));
                uncomplete--;
                if(uncomplete == 0){
                    cout<<table[cz][cy][cx];
                    return;
                }
            }
        }
        
        for(int i = 0 ; i<2 ; i++){
            nz = cz + dz[i];
            if(0<=nz && nz < h && table[nz][cy][cx] == 0){
                table[nz][cy][cx] = table[cz][cy][cx]+1;
                q.push(pos(nz, cy, cx));
                uncomplete--;
                if(uncomplete == 0){
                    cout<<table[cz][cy][cx];
                    return;
                }
            }
        }
        
    }
    cout<<-1<<endl;
}


queue<pos> build(){
    queue<pos> starts;
    uncomplete = 0;
    int input;
    for(int z = 0 ; z < h ; z++){
        for(int y = 0 ; y < n ; y++){
            for(int x = 0 ; x < m ; x++){
                cin>>input;
                if (input == 0){
                    uncomplete++;
                }else if (input == 1){
                    //printf("STARTS : %d %d %d\n", z, y, x);
                    starts.push(pos(z, y, x));
                }
                table[z][y][x] = input;
            }
        }
    }
    return starts;
}


int main(int argc, const char * argv[]) {
    cin>>m>>n>>h;
    queue<pos> starts = build();
    if(uncomplete==0){
        cout<<0<<endl;
        return 0;
    }
    //cout<<uncomplete<<endl;
    bfs(starts);
    

    return 0;
}

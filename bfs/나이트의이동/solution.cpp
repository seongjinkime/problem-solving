//
//  main.cpp
//  7562_나이트의이동
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 301

using namespace std;


typedef pair<int, int> point;



int dx[] {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] {-2, -1, 1, 2, 2, 1, -1, -2};

int bfs(){
    int table[MAX][MAX] = {0};
    int len;
    int sy, sx, ty, tx;
    int cy, cx, ny, nx;
    
    scanf("%d", &len);
    scanf("%d %d %d %d", &sy, &sx, &ty, &tx);
    
    queue<point>q;
    q.push(point(sy, sx));

    table[sy][sx]=0;
    
    
    while(!q.empty()){
        point here = q.front();
        q.pop();
        cy = here.first;
        cx = here.second;
        
        if(cy == ty && cx == tx){
            return table[cy][cx];
        }
        
        for(int i = 0 ; i < 8 ; i++){
            ny = cy + dy[i];
            nx = cx + dx[i];
            if(0<=ny && ny<len && 0<=nx && nx<len && table[ny][nx]==0){
                q.push(point(ny,nx));
                table[ny][nx] = table[cy][cx]+1;
            }
        }
        
    }
       
    return table[ty][tx];
         
}


int main(int argc, const char * argv[]) {
    int t, cy, cx, ty, tx;
    cin>>t;
    
    for(int i = 0 ; i < t ; i++){
        cout<<bfs()<<endl;
    }
    
    
    return 0;
}

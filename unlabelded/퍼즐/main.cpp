#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#define len 3

using namespace std;
typedef pair<int, int> pos;
int table[len][len];
int visited[len][len];
//udrl
int dy[4] {-1, 1, 0 ,0};
int dx[4] {0, 0, -1 ,1};

bool isRange(int y, int x){
    return (0<=y) && (y < len) && (0<=x) && (x < len);
}

bool qualified(int y, int x){

    
    int newPos[2] {x-1, x+1};
    int a = table[y][x];
    for(int i = 0 ; i < 2 ; i++){
        int nx = newPos[i];
        if(isRange(y, nx) && table[y][nx] != 0){
            int b = table[y][nx];
            if (abs(a-b) != 1){
                
                return false;
            }
        }
    }
    
    return true;
}

int bfs(pos start){
    int cy, cx, ny, nx;
    queue<pos> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    while(!q.empty()){
        pos here = q.front();
        cy = here.first;
        cx = here.second;
        q.pop();
        if(cy == len-1 && cx == len-1){
            return visited[cy][cx]-1;
        }
        for(int i = 0 ; i <  4 ; i++){
            ny = cy + dy[i];
            nx = cx + dx[i];
            
            if(isRange(ny, nx) && visited[ny][nx] == 0){
                swap(table[cy][cx], table[ny][nx]);
                if(qualified(cy, cx)){
                    visited[ny][nx] = visited[cy][cx] + 1;
                    q.push(pos(ny, nx));
                }else{
                    swap(table[cy][cx], table[ny][nx]);
                }
            }
        }
    }
    return -1;
}

pos build(){
    pos s;
    for(int y = 0 ; y <  3 ; y++){
        for(int x = 0 ; x < 3 ; x++){
            cin>>table[y][x];
            if(table[y][x] == 0){
                s = pos(y,x);
            }
        }
    }
    return s;
}
int main(int argc, const char * argv[]) {
    pos start = build();
    int dist = bfs(start);
    cout<<dist<<endl;
    //cout<<isSequence(1);
    
    return 0;
}

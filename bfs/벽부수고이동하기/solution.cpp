#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define UNCRASHED 0
#define CRASHED 1

using namespace std;
typedef struct _WALKER{
    int y, x;
    int status;
    
    _WALKER(int _y, int _x, int _s){
        y = _y;
        x = _x;
        status = _s;
    }
}walker;

int map[MAX][MAX];
int visited[2][MAX][MAX];
int n, m;
//udrl
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, 1, -1};

int bfs(){
    int cy, cx, ny, nx, status;
    queue<walker> q;
    q.push(walker(0, 0, UNCRASHED));
    visited[UNCRASHED][0][0] = 1;
    
    while(!q.empty()){
        walker current = q.front();
        q.pop();
        cy = current.y;
        cx = current.x;
        status = current.status;
        
        if(cy == n-1 && cx == m-1){
            return visited[status][cy][cx];
        }
        
        for(int i = 0 ; i < 4 ; i++){
            ny = cy + dy[i];
            nx = cx + dx[i];
            if(0<=ny && ny<n && 0<=nx && nx<m){
                if(map[ny][nx] == 0 && visited[status][ny][nx] == 0){
                    visited[status][ny][nx] = visited[status][cy][cx] + 1;
                    q.push(walker(ny, nx, status));
                }
                if(map[ny][nx] == 1 && status == UNCRASHED){
                    visited[CRASHED][ny][nx] = visited[UNCRASHED][cy][cx] + 1;
                    q.push(walker(ny, nx, CRASHED));
                }
            }
        }
        
    }
    return -1;
    
}

void build(){
    for(int y = 0 ; y<n ; y++){
        for(int x = 0 ; x<m ; x++){
            scanf("%1d", &map[y][x]);
        }
    }
}

int main(){
    cin>>n>>m;
    build();
    cout<<bfs()<<endl;
    return 0;
}

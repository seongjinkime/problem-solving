#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef vector<vector<int>> table;
typedef vector<vector<bool>> crashed;
typedef pair<int, int> pos;
map<table, int> dist;

int dy[4] {-1,1,0,0};
int dx[4] {0,0,-1,1};
int n, ret;

void mvBlock(table& t, crashed& c, int sy, int sx, int i){
    int ny, nx;
    int next, prev;
    bool first = false;
    ny = nx = 0;
    
    while(true){
        ny = sy + dy[i];
        nx = sx + dx[i];
        
        if(ny < 0 || ny >= n)
            break;
        if(nx < 0 || nx >= n)
            break;
        
        if(t[ny][nx] == 0){
            swap(t[ny][nx], t[sy][sx]);
            sy = ny;
            sx = nx;
            continue;
        }else{
            next = t[ny][nx];
            prev = t[sy][sx];
            
            if(next == prev && !c[ny][nx] && !first){
                t[ny][nx] *= 2;
                t[sy][sx] = 0;
                first = true;
                c[ny][nx] = true;
                sy = ny;
                sx = nx;
                continue;
            }else{
                break;
            }
            
        }
        
        
    }
   
}



void move(table& t, int i){
    
    crashed c = crashed(n, vector<bool>(n, false));
    //up
    if(i == 0){
        for(int y = 0 ; y < n ; y++){
            for(int x = 0 ; x < n ; x++){
                if(t[y][x] == 0)
                    continue;
                mvBlock(t, c, y, x, i);
            }
        }
    }
    //down
    if(i == 1){
        for(int y = n-1 ; y >= 0 ; y--){
            for(int x = 0 ; x < n ; x++){
                if(t[y][x] == 0)
                    continue;
                mvBlock(t, c, y, x, i);
            }
        }
    }
    //left
    if(i == 2){
        for(int x = 0 ; x < n ; x++){
            for(int y = 0 ; y < n ; y++){
                if(t[y][x] == 0)
                    continue;
                mvBlock(t, c, y, x, i);
            }
        }
    }
    //right
    if(i == 3){
        for(int x = n-1 ; x >= 0 ; x--){
            for(int y = 0 ; y < n ; y++){
                if(t[y][x] == 0)
                    continue;
                mvBlock(t, c, y, x, i);
            }
        }
    }
    
}

int maxBlock(table t){
    int num = 0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            num = max(num, t[y][x]);
        }
    }
    return num;
}

void bfs(table start){
    queue<table> q;
    dist[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        table current = q.front();
        q.pop();
        ret = max(ret, maxBlock(current));
        
        if(dist[current]>=5){
            continue;
        }
        
        for(int i = 0 ; i < 4 ; i++){
            table nt = current;
            move(nt, i);
            if(dist.count(nt)>0)
                continue;
            dist[nt] = dist[current] + 1;
            q.push(nt);
        }
        
    }
}

table build(){
    cin>>n;
    table t = table(n, vector<int>(n));
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cin>>t[y][x];
        }
    }
    return t;
}


int main(int argc, const char * argv[]) {
    table start = build();
    bfs(start);
    cout<<ret<<endl;
    return 0;
}

//
//  main.cpp
//  12100_2048(easy)
//
//  Created by Kim Seong Jin on 2019. 12. 12..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define MAX_TRY 5
#define MAX_SIZE 21

using namespace std;

typedef pair<int,int> pos;
typedef vector<vector<int>> table;

int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, -1, 1};
map<table, int> dist;
table origin;
int n;

void print(table t){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            printf("%2d ", t[y][x]);
        }
        cout<<endl;
    }
    cout<<endl;
}

bool inRange(int y, int x){
    return 0<=y && y < n && 0<= x && x < n;
}

void move(table& t, table& c, int y, int x, int d){
    int my = dy[d];
    int mx = dx[d];
    bool isFirst = true;
    while(inRange(y + my, x + mx)){
        bool isEmpty = t[y+my][x+mx] == 0;
        bool isSame =  t[y+my][x+mx] == t[y][x];
        bool collapsed = c[y+my][x+mx]==1; //!
        //print(c);
        if(isEmpty){
            swap(t[y][x], t[y+my][x+mx]);
            y += my;
            x += mx;
            continue;
        }
        
        if(isSame && isFirst && !collapsed){
            t[y+my][x+mx] = t[y][x] * 2;
            t[y][x] = 0;
            isFirst = false;
            c[y+my][x+mx] = 1;
            //cout<<y+my<<","<<x+mx<<" collapsed"<<endl;
            //cout<<c[y+my][x+mx]<<endl;;
            y += my;
            x += mx;
            
            continue;
        }else{
            break;
        }
        
        
    }
}

void moveBlocks(table& t, int d){
    table c = table(n, vector<int>(n, 0));
    switch(d){//!
        case 0:
            for(int y = 0 ; y < n ; y++){
                for(int x = 0 ; x < n ; x++){
                    if(t[y][x] == 0)
                        continue;
                    move(t, c, y, x, d);
                }
            }
            break;
        case 1:
            for(int y = n-1 ; y >= 0 ; y--){
                for(int x = 0 ; x < n ; x++){
                    if(t[y][x] == 0)
                        continue;
                    move(t, c, y, x, d);
                }
            }
            break;
        case 2:
            for(int x = 0 ; x < n ; x++){
                for(int y = 0 ; y < n ; y++){
                    if(t[y][x] == 0)
                        continue;
                    move(t, c, y, x, d);
                }
            }
            break;
        case 3:
            for(int x = n-1 ; x >= 0 ; x--){
                for(int y = 0 ; y < n ; y++){
                    if(t[y][x] == 0)
                        continue;
                    move(t, c, y, x, d);
                }
            }
            break;

    }
    
}

int biggest(table t, int& cnt){
    int ret = 0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            ret = max(ret, t[y][x]);
            cnt++;
        }
    }
    return ret;
}

bool visited(table t){
    return dist.count(t)>0;
}

int bfs(table start){
    table nt;
    int blockNum, ret, num;
    queue<table> q;
    
    dist[start] = 0;
    q.push(start);
    blockNum = ret = 0;
    
    while(!q.empty()){
        table current = q.front();
        q.pop();
        if(dist[current] >= MAX_TRY){
            ret = max(ret, biggest(current, blockNum));
            continue;
        }
        //cout<<"CURRENT"<<endl;
        //print(current);
        for(int i = 0 ; i < 4 ; i++){
            blockNum = 0;
            nt = current;
            moveBlocks(nt, i);
            
            //cout<<"MOVE TO "<<i<<endl;
            //print(nt);
            num = biggest(nt, blockNum);
            if(blockNum == 1){
                return num;
            }else{
                ret = max(ret, num);
            }
            
            if(visited(nt))
                continue;
            
            dist[nt] = dist[current]+1;
            q.push(nt);
        }
    }
    
    return ret;
    
}

void build(){
    origin = table(n, vector<int>(n));
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cin>>origin[y][x];
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    cout<<bfs(origin)<<endl;
    //print(origin);
    return 0;
}

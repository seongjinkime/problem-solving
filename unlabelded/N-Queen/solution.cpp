//
//  main.cpp
//  9663_N-Queen
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 15

using namespace std;
int table[MAX][MAX];
int n;

bool overlap(int y, int x, int dist){
    int dy[8] {0, 0, -1, 1, -1, -1, 1, 1};
    int dx[8] {-1, 1, 0, 0, -1, 1, -1, 1};
    
    for(int d = 1; d <= dist ; d++){
        for(int i = 0 ; i < 8 ; i++){
            int ny = y + (dy[i] * d);
            int nx = x + (dx[i] * d);
           
            if(0<=ny && ny < n && 0 <= nx && nx < n){
                if(table[ny][nx] == 1)
                    return true;
            }
        }
    }
    return false;
}
void print(){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cout<<table[y][x];
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isAvailable(int y, int x, int dist){
    table[y][x] = 1;
    x+=1;
    int cnt = 1;
    
    while(y<n){
        while(x<n){
            if(!overlap(y, x, dist)){
                table[y][x] = 1;
                cnt++;
                if(cnt==n)
                    return true;
            }
            x++;
        }
        x = 0;
        y++;
    }
    return false;
}

void init(){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            table[y][x] = 0;
        }
    }
}

void solve(){
    int cnt = 0;
    for(int dist = 1 ; dist<=n; dist++){
        for(int y = 0 ; y < n ; y++){
            for(int x = 0 ; x < n ; x++){
                
                if(isAvailable(y, x, dist)){
                    cnt++;
                }
                init();
            }
        }
        
    }
    
    cout<<cnt<<endl;
}


int main(int argc, const char * argv[]) {
    n = 8;
    solve();
    //table[0][0] = 1;
    //cout<<overlap(0, 2, 1)<<endl;
    return 0;
}

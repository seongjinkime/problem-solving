//
//  main.cpp
//  1525_퍼즐
//
//  Created by Kim Seong Jin on 26/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <map>

#define len 3
#define target "123456789"

using namespace std;
//udrl
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, -1, 1};


int bfs(string start){
    queue<string> q;
    map<string, int> visited;
    visited[start] = 0;
    q.push(start);
    int cnt = 0;
    while(!q.empty()){
        string current = q.front();
        //cout<<table<<endl;
        int idx = current.find('9');
        int y = idx / len;
        int x = idx % len;
        q.pop();
        if(current==target){
            return visited[current];
        }
        for(int i = 0 ; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0<=ny && ny < len && 0 <= nx && nx < len){
                string tmp = current;
                swap(tmp[y * 3 + x], tmp[ny * 3 + nx]);
                if(visited.count(tmp)==0){
                    visited[tmp] = visited[current]+1;
                    q.push(tmp);
                    cnt++;
                }
            }
        }
    }
    return -1;
}

string build(){
    string table = "";
    int num;
    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < len ; j++){
            cin>>num;
            if(num == 0)
                table += "9";
            else
                table += to_string(num);
        }
    }
    return table;
}

int main(int argc, const char * argv[]) {
    
    string s = build();
    cout<<bfs(s)<<endl;
    
    return 0;
}

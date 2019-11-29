//
//  main.cpp
//  2251_물통
//
//  Created by Kim Seong Jin on 2019. 11. 28..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int size[3];
vector<int> ret;

void move(int a, int b, vector<int>& water){
    if(water[a] + water[b] > size[b]){
        water[a] = water[a] - (size[b] - water[b]);
        water[b] = size[b];
    }else{
        water[b] = water[a] + water[b];
        water[a] = 0;
    }
}

void bfs(vector<int> start){
    set<vector<int>> s;
    queue<vector<int>>q;
    
    q.push(start);
    s.insert(start);
    while(!q.empty()){
        vector<int> current = q.front();
        q.pop();
        if(current[0] == 0){
            ret.push_back(current[2]);
        }
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(i==j)
                    continue;
                vector<int> tmp = current;
                move(i, j, tmp);
                if(s.count(tmp)==0){
                    q.push(tmp);
                    s.insert(tmp);
                }
            }
        }

    }
    
}

int main(int argc, const char * argv[]) {
    
    for(int i = 0 ; i < 3; i++){
        cin>>size[i];
    }

    vector<int> start {0, 0, size[2]};
    bfs(start);
    sort(ret.begin(), ret.end());
    for(int w : ret){
        cout<<w<<" ";
    }
    cout<<endl;
    return 0;
}

//
//  main.cpp
//  15686_치킨배달
//
//  Created by Kim Seong Jin on 2020. 1. 5..
//  Copyright © 2020년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define INF 987654321
#define MAX 51
#define HOUSE 1
#define CHICKEN 2
using namespace std;
struct pos{int y, x;};
int map[MAX][MAX];
int ret, n,m;
vector<pos>chickens, houses;
vector<bool> selected;


vector<int> dists(){
    vector<int> dist(houses.size(), INF);
    for(int i = 0 ; i < houses.size() ; i++){
        pos house = houses[i];
        for(int j = 0 ; j <  chickens.size() ; j++){
            if(!selected[j]) continue;
            pos chicken = chickens[j];
            dist[i] = min(dist[i], abs(house.y - chicken.y) + abs(house.x - chicken.x));
        }
    }
    return dist;
}

void update(){
    int total = 0;
    vector<int> dist = dists();
    for(int d : dist) total+=d;
    ret = min(ret, total);
}

void dfs(int here, int cnt){
    if(cnt == m){
        update();
        return;
    }
    for(int there = here ; there < chickens.size() ; there++){
        if(!selected[there]){
            selected[there] = true;
            dfs(there, cnt+1);
            selected[there] = false;
        }
    }
}


void build(){
    cin>>n>>m;
    ret = INF;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cin>>map[y][x];
            if(map[y][x] == HOUSE){
                houses.push_back({y,x});
            }else if(map[y][x] == CHICKEN){
                chickens.push_back({y,x});
            }
        }
    }
    selected = vector<bool>(chickens.size(), false);
}


int main(int argc, const char * argv[]) {
    build();
    dfs(0, 0);
    cout<<ret<<endl;
    return 0;
}

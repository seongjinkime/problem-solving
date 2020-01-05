//
//  main.cpp
//  15683_감시
//
//  Created by Kim Seong Jin on 2020. 1. 5..
//  Copyright © 2020년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define U 0
#define D 1
#define R 2
#define L 3
#define MAX 9

using namespace std;
struct pos{int y, x;};
int map[MAX][MAX];
int origin[MAX][MAX];
vector<int> directions;
vector<pos> cameras;
int camCnt;
int ret;
int n, m;

void checkU(pos cam){
    while(cam.y - 1 >=0 && map[cam.y-1][cam.x] != 6){
        cam.y -= 1;
        if(map[cam.y][cam.x] == 0)
            map[cam.y][cam.x] = -1;
    }
}

void checkD(pos cam){
    while(cam.y + 1 < n && map[cam.y+1][cam.x] != 6){
        cam.y += 1;
        if(map[cam.y][cam.x] == 0)
            map[cam.y][cam.x] = -1;
    }
}

void checkL(pos cam){
    while(cam.x - 1 >= 0 && map[cam.y][cam.x-1] != 6){
        cam.x -= 1;
        if(map[cam.y][cam.x] == 0)
            map[cam.y][cam.x] = -1;
    }
}

void checkR(pos cam){
    while(cam.x + 1 < m && map[cam.y][cam.x + 1] != 6){
        cam.x += 1;
        if(map[cam.y][cam.x] == 0)
            map[cam.y][cam.x] = -1;
    }
}

void see(pos cam, int rotation){
    int type = map[cam.y][cam.x];
    
    if(type == 1){
        if(rotation == 0){
            checkR(cam);
        }else if(rotation == 1){
            checkD(cam);
        }else if(rotation == 2){
            checkL(cam);
        }else if(rotation == 3){
            checkU(cam);
        }
    }else if(type == 2){
        if(rotation == 0 || rotation == 2){
            checkR(cam);
            checkL(cam);
        }else if(rotation == 1 || rotation == 3){
            checkU(cam);
            checkD(cam);
        }
    }else if(type == 3){
        if(rotation == 0){
            checkU(cam);
            checkR(cam);
        }else if(rotation == 1){
            checkR(cam);
            checkD(cam);
        }else if(rotation == 2){
            checkD(cam);
            checkL(cam);
        }else if(rotation == 3){
            checkU(cam);
            checkL(cam);
        }
    }else if(type == 4){
        if(rotation == 0){
            checkU(cam);
            checkR(cam);
            checkL(cam);
        }else if(rotation == 1){
            checkU(cam);
            checkR(cam);
            checkD(cam);
        }else if(rotation == 2){
            checkL(cam);
            checkR(cam);
            checkD(cam);
        }else if(rotation == 3){
            checkU(cam);
            checkL(cam);
            checkD(cam);
        }
    }else if(type == 5){
        checkU(cam);
        checkR(cam);
        checkL(cam);
        checkD(cam);
    }
    
}


void rotate(int cnt){
    if(cnt == camCnt){
        copy(&origin[0][0], &origin[0][0] + MAX * MAX, &map[0][0]);
        for(int i = 0 ; i < cnt ; i++){
            //cout<<i<<directions[i]<<endl;
            see(cameras[i], directions[i]);
        }
        int safe = 0;
        for(int y = 0 ; y < n ; y++){
            for(int x = 0; x < m ; x++){
                safe += map[y][x] == 0 ? 1 : 0;
            }
        }
        ret = min(ret, safe);
        
        return;
    }
    
    for(int i = 0 ; i < 4 ; i++){
        directions.push_back(i);
        rotate(cnt+1);
        directions.pop_back();
    }
}

void build(){
    cin>>n>>m;
    ret = n * m;
    
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cin>>origin[y][x];
            if(origin[y][x] != 6 && origin[y][x] != 0)
                cameras.push_back({y,x});
        }
    }
    camCnt = cameras.size();
}

int main(int argc, const char * argv[]) {
    build();
    rotate(0);
    cout<<ret<<endl;
    return 0;
}

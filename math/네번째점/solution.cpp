//
//  main.cpp
//  3009_네번째점
//
//  Created by Kim Seong Jin on 21/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int> xPoints, yPoints;

int main(int argc, const char * argv[]) {
    map<int, int>mapx, mapy;
    
    int y, x;
    for(int i = 0 ; i < 3 ; i++){
        cin>>y>>x;
        if(mapy.count(y) == 0){
            yPoints.push_back(y);
            mapy[y] = 1;
        }else{
            mapy[y] += 1;
        }
        
        if(mapx.count(x) == 0){
            xPoints.push_back(x);
            mapx[x] = 1;
        }else{
            mapx[x] = mapx[x]+1;
        }
    }
    
    for(int i = 0 ; i < yPoints.size() ; i++){
        y = yPoints[i];
        if(mapy[y] == 1)
            cout<<y;
    }
    
    cout<<" ";
    
    for(int i = 0 ; i < xPoints.size() ; i++){
        x = xPoints[i];
        if(mapx[x] == 1)
            cout<<x;
    }
    cout<<endl;

    
    return 0;
}

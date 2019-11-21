//
//  main.cpp
//  1085_직사각형에서탈출
//
//  Created by Kim Seong Jin on 21/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    int x,y,w,h;
    int gapW, gapH;
    int ret;
    
    cin>>x>>y>>w>>h;
    gapW = min(abs(x-0), abs(x-w));
    gapH = min(abs(y-0), abs(y-h));
    ret = min(gapH, gapW);
    cout<<ret<<endl;
    return 0;
}

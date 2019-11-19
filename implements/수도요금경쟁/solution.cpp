//
//  main.cpp
//  2707_ 수도요금경쟁
//
//  Created by Kim Seong Jin on 19/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>

using namespace std;

void solve(int t){
    int p, q, r, w, s;
    int pa, pb;
    
    cin>>p>>q>>r>>s>>w;
    pa = w*p;
    pb = q;
    
    if(w>r)
        pb += (w-r)*s;
    
    printf("#%d %d", t, min(pa, pb));
    
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
        solve(i);
    }
    return 0;
}

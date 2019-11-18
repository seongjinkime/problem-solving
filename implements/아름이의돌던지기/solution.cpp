//
//  main.cpp
//  1285_아름이의돌던지기
//
//  Created by Kim Seong Jin on 18/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

void solve(int t){
    int n, num;
    int minimum, cnt;
    priority_queue<int> q;
    
    cnt = 0;
    cin>>n;
    
    for(int i = 0 ; i < n ; i++){
        cin>>num;
        q.push(abs(num-0) * -1);
    }
    
    minimum = q.top();

    while(!q.empty() && q.top() == minimum){
        cnt++;
        q.pop();
       
    }
    minimum *= -1;
    
    printf("#%d %d %d\n", t, minimum, cnt);
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
        solve(i);
    }
    
    return 0;
}

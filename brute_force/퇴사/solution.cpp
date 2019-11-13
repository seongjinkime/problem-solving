//
//  main.cpp
//  14501_퇴사
//
//  Created by Kim Seong Jin on 12/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int ret;
int n;
vector<int>t,p;
vector<bool> selected;

void dfs(int day, int sum){
    if(day >= n+1){
        ret = max(ret, sum);
        return;
    }
    
    if(day+t[day]<=n+1 ){
        dfs(day+t[day], sum+p[day]);
    }
    if(day+1 <= n+1){
        dfs(day+1, sum);
    }
}

void build(){
    t = p = vector<int>(n+1);
    
    for(int i = 1 ; i <= n ; i++){
        cin>>t[i]>>p[i];
    }
}
int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    dfs(1, 0);
    cout<<ret<<endl;
    return 0;
}

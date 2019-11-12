//
//  main.cpp
//  1946_간단한압축풀기
//
//  Created by Kim Seong Jin on 12/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

typedef pair<char, int> info;
typedef queue<info> infos;

info getInfo(){
    char ch;
    int num;
    cin>>ch>>num;
    return info(ch, num);
}

queue<info> build(){
    int n;
    cin>>n;
    queue<info> q;
    for(int i = 0 ; i < n ; i++)
        q.push(getInfo());
    return q;
}

void solve(int t){
    queue<info> infos = build();
    cout<<"#"<<t<<endl;
    int cnt = 0;
    while(!infos.empty()){
        char ch = infos.front().first;
        cout<<ch;

        cnt++;
        if(cnt==10){
            cout<<endl;
            cnt=0;
        }
        
        infos.front().second-=1;
        if(infos.front().second==0){
            infos.pop();
        }
        
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
        solve(i);
    }
    return 0;
}

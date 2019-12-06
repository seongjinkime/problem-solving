//
//  main.cpp
//  1251_단어나누기
//
//  Created by Kim Seong Jin on 05/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 51

using namespace std;
vector<string> strs;
int nums[MAX];
bool selected[MAX];
int len;
string s;
string ret;

void sum(int idx[2]){
    string a (s.begin(), s.begin()+idx[0]);
    string b (s.begin()+idx[0], s.begin()+idx[1]);
    string c (s.begin()+idx[1], s.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    string total = a+b+c;
    strs.push_back(total);
    //ret = min(ret, total);
    //cout<<total<<endl;
    //cout<<a<<"/"<<b<<"/"<<c<<endl;
}
void dfs(int here, int cnt){
    if(cnt == 2){
        int idxs[2];
        int idx = 0;
        for(int i = 0 ; i < len ; i++){
            if(selected[i])
                idxs[idx++] = nums[i];
                //cout<<nums[i]<<" ";
        }
        sum(idxs);
        //cout<<endl;
        return;
    }
    
    for(int there = here ; there < len ; there++){
        if(!selected[there]){
            selected[there] = true;
            dfs(there, cnt+1);
            selected[there] = false;
        }
    }
}

void build(){
    for(int i = 0 ; i <= len ; i++){
        nums[i] = i;
    }
}
int main(int argc, const char * argv[]) {
    cin>>s;
    
    
    len = s.size();
    build();
    dfs(1, 0);
    sort(strs.begin(), strs.end());
    cout<<strs[0]<<endl;
    return 0;
}

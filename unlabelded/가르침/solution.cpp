//
//  main.cpp
//  1062_가르침
//
//  Created by Kim Seong Jin on 09/12/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


#define MAX_N 51
#define MAX_K 27
#define EMPTY ""
using namespace std;
vector<string> inputs;
bool contains[MAX_K];
char alphabets[MAX_K];
bool selected[MAX_K];
int n,k;
int ret;

bool learned(string s){
    for(int idx = 0 ; idx < s.size() ; idx++){
        char ch = s[idx];
        if(!selected[ch-'a'])
            return false;
    }
    return true;
}

int completeNum(){
    int cnt = 0;
    for(int i = 0 ; i <  inputs.size() ; i++){
        if(learned(inputs[i])){
            cnt++;
        }
    }
    
    return cnt;
}

void dfs(int here, int cnt){
    if(cnt == k){
        int learnCnt = completeNum();
        ret = max(ret, learnCnt);
        return;
    }
    
    for(int there = here ; there < MAX_K ; there++){
        if(!selected[there]){
            selected[there] = true;
            dfs(there, cnt+1);
            selected[there] = false;
        }
    }
}

void preLearn(){
    char pre[5] {'a','c', 'i', 'n', 't'};
    for(int i = 0 ; i < 5 ; i++){
        char ch = pre[i];
        selected[ch-'a'] = true;
        k-=1;
    }
}

string filter(string s){
    return s.substr(4, (s.size()-8));
}

void build(){
    ret = 0;
    inputs = vector<string>(n);
    string s;
    for(int idx = 0 ; idx < MAX_K ; idx++){
        alphabets[idx] = 'a'+idx;
    }
    
    for(int i = 0 ; i < n ; i++){
        cin>>s;
        s = filter(s);
        inputs[i] = s;
    }
   
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>k;    
    preLearn();

    build();
    dfs(0, 0);
    cout<<ret<<endl;
    return 0;
}

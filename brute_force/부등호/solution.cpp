//
//  main.cpp
//  2529_부등호
//
//  Created by Kim Seong Jin on 15/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#define MAX 10

using namespace std;

vector<int>permutation;
vector<bool> selected;
vector<string> availables;
vector<char> op;
int n;

bool pass(){
    for(int i = 0, pos = 0 ; i < op.size() ; i++, pos++){
        if((op[i] == '>') && (permutation[pos] < permutation[pos+1]))
            return false;
        if((op[i] == '<') && (permutation[pos] > permutation[pos+1]))
            return false;
    }
    return true;
}

void addAvailable(){
    string s = "";
    for(int i = 0 ; i < permutation.size() ; i++){
        s += to_string(permutation[i]);
    }
    availables.push_back(s);
}

void dfs(int cnt){
    if(cnt == n+1){
        if(pass()){
            addAvailable();
        }
        
    }
    for(int i = 0 ; i < 10; i++){
        if(!selected[i]){
            selected[i] = true;
            permutation.push_back(i);
            dfs(cnt+1);
            permutation.pop_back();
            selected[i] = false;
        }
    }
}

void build(){
    op = vector<char>(n);
    selected = vector<bool>(11);
    for(int i = 0 ; i < n ; i++){
        cin>>op[i];
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    dfs(0);
   
    cout<<availables.back()<<endl;
    cout<<availables.front()<<endl;

    return 0;
}

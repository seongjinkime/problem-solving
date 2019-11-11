//
//  main.cpp
//  6603_로또
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 14

using namespace std;
vector<int> s;
vector<bool> selected;
int k;

void print(){
    for(int i = 0 ; i < k ; i++){
        if(selected[i]){
            cout<<s[i]<<" ";
        }
    }
    cout<<endl;
}

void combination(int here, int cnt){
    if(cnt==6){
        print();
        return;
    }
    for(int there = here ; there<k ; there++){
        if(!selected[there]){
            selected[there] = true;
            combination(there, cnt+1);
            selected[there]=false;
        }
    }
}

void build(){
    s = vector<int>(k, 0);
    selected = vector<bool>(k, false);
    for(int i = 0 ; i < k ; i++){
        cin>>s[i];
    }
    
}



int main(int argc, const char * argv[]) {
    while(true){
        cin>>k;
        if(k==0)
            break;
        build();
        combination(0, 0);
        cout<<endl;
    }
    return 0;
}

//
//  main.cpp
//  1288_새로운불면증치료법
//
//  Created by Kim Seong Jin on 18/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;

set<char> s;

bool isFull(int num){
    
    string nstr = to_string(num);
    for(int i = 0 ; i < nstr.size() ; i++){
        s.insert(nstr[i]);
        if(s.size() >= 10)
            return true;
    }
    return false;
}

void solve(int t){
    s.clear();
    int input, num;
    cin>>input;
    
    num = input;
    
    while (!isFull(num)) {
        num += input;
    }
    printf("#%d %d\n", t, num);
}


int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    
    for(int i = 1 ; i <= t ; i++){
        solve(i);
    }
    return 0;
}

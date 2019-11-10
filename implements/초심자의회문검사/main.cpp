//
//  main.cpp
//  1989_초심자의회문검사
//
//  Created by Kim Seong Jin on 01/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void solution(int t, string s){
    int n = s.size();
    int mid = n/2;
    bool isSame;
    
    string prefix, postfix;
    if(n%2==0){
        prefix = s.substr(0, mid);
    }else{
        prefix = s.substr(0, mid+1);
    }
    string postFix = s.substr(mid, n);
    reverse(postFix.begin(), postFix.end());
    
    isSame = prefix == postFix;
    
    printf("#%d %d\n", t, isSame);
    
    

}

int main(int argc, const char * argv[]) {
    int t;
    string s;
    cin>>t;
    
    for(int i = 1; i <= t ; i++){
        cin>>s;
        solution(i, s);
    }
    return 0;
}

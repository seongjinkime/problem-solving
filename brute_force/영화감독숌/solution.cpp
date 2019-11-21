//
//  main.cpp
//  1436_영화감독숌
//
//  Created by Kim Seong Jin on 21/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
int n;

bool isTitle(LL num){
    string nstr = to_string(num);
    for(int i = 0 ; i < nstr.size()-2 ; i++){
        string sub = nstr.substr(i, 3);
        //cout<<sub<<endl;
        if(sub == "666")
            return true;
    }
    return false;
}

LL solve(){
    LL num = 665;
    int cnt = 0;
    while (true) {
        if(isTitle(num)){
            cnt++;
            if(cnt==n){
                return num;
            }
        }
        num++;
    }
    
    return num;
}

int main(int argc, const char * argv[]) {
    cin>>n;
    cout<<solve()<<endl;
    return 0;
}

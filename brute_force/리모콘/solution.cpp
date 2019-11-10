//
//  main.cpp
//  1107_리모콘
//
//  Created by Kim Seong Jin on 02/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define INF 987654321
#define MAX 500001*2

using namespace std;
vector<char> brokens;
bool validate(int num){
    int total=0;
    string s = to_string(num);
    for(char b : brokens){
        if(count(s.begin(), s.end(), b)>0)return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int n, b;
    cin>>n>>b;
    brokens = vector<char>(b);
    for(int i = 0 ; i < b ; i++){
        cin>>brokens[i];
    }
    int tryA, tryB;
    
    tryA = abs(n-100);
    int num = 0;
    int minNum;
    tryB = INF;
    
    while (num<MAX){
        if(validate(num)){
            int move = abs(n-num);
            if(tryB > move){
                tryB = move;
                minNum = num;
            }
        }
        num++;
    }
    //cout<<minNum<<endl;
    tryB += to_string(minNum).size();
    //cout<<tryA<<" "<<tryB<<" "<<tryC<<endl;
    cout<<min(tryA, tryB)<<endl;
    return 0;
}

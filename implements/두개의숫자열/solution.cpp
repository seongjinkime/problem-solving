//
//  main.cpp
//  1959_두개의숫자열
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> longest, small;

void build(){
    int sizeA, sizeB,tmp;
    cin>>sizeA>>sizeB;
    vector<int> a = vector<int>(sizeA);
    vector<int> b = vector<int>(sizeB);
    
    for(int i = 0 ; i < sizeA ; i++)
        cin>>a[i];
    for(int i = 0 ; i < sizeB ; i++)
        cin>>b[i];
    
    if(sizeA < sizeB){
        longest = b;
        small = a;
    }else{
        longest = a;
        small = b;
    }
}

void solve(int t){
    build();
    int ret = 0;
    for(int idx = 0 ; idx+small.size() <= longest.size() ; idx++){
        int sum = 0;
        for(int walker = 0 ; walker < small.size() ; walker++){
            sum += small[walker] * longest[idx+walker];
        
        }
        
        ret = max(sum, ret);
    }
    printf("#%d %d\n", t, ret);
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int  i = 1; i <= t ;i++){
        solve(i);
    }
    return 0;
}

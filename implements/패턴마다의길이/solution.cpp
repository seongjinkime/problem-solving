//
//  main.cpp
//  2007_패턴마다의길이
//
//  Created by Kim Seong Jin on 31/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution(int tNum, string s){
    int pivot =1;
    int last = s.size()-1;
    while(s.substr(0, pivot+1)!=s.substr(pivot+1, pivot+1)){
         pivot++;
     }
     
    printf("#%d %d\n", tNum, pivot+1);
    
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<string> arr(n);
    
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    
    for(int t = 1 ; t<=n ; t++){
        solution(t, arr[t-1]);
    }
    
    
    return 0;
}

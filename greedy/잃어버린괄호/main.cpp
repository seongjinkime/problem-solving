//
//  main.cpp
//  1541_잃어버린괄호(retry)
//
//  Created by Kim Seong Jin on 08/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void solution(string s){
    int sum=0;
    int pivot=0;
    string tmp = "";
    bool minus = false;
        
    while(pivot<=s.size()){
        if(s[pivot] == '+' || s[pivot] == '-' || s[pivot]=='\0'){
            if(tmp[0]=='-'){
                minus = true;
            }
            if(minus){
                tmp[0] = '-';
            }
            sum += stoi(tmp);
            
            tmp="";
        }
        tmp += s[pivot];
        pivot++;
    }
    cout<<sum<<endl;
    
}

int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    solution(s);
    return 0;
}

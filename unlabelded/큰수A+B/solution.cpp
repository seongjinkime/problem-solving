//
//  main.cpp
//  10757_큰수A+B
//
//  Created by Kim Seong Jin on 2019. 12. 12..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sum(string a, string b){
    int idxA = a.size()-1;
    int idxB = b.size()-1;
    string ret (max(a.size(), b.size()), '0');
    int idxSum = ret.size()-1;
    
    int sum;
    bool overTen = false;
    while(idxA>=0 || idxB>=0){
        sum = 0;
        //cout<<a[idxA]-'0'<<endl;
        //cout<<a[idxB]-'0'<<endl;
        if(idxA>=0)
            sum += a[idxA] - '0';
        if(idxB>=0)
            sum += b[idxB] - '0';
        
        if(overTen){
            sum += 1;
            overTen = false;
        }
        
        //cout<<sum<<endl;
        //cout<<idxSum<<endl;
        ret[idxSum] = (sum%10) + '0';
        //cout<<ret<<endl;
        if(sum>=10)
            overTen = true;
        
        idxA--;
        idxB--;
        idxSum--;
    }
    if(overTen){
        ret = "1" + ret;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    string a,b;
    cin>>a>>b;
    cout<<sum(a, b)<<endl;
    
    return 0;
}

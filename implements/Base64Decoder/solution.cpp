//
//  main.cpp
//  1928_Base64Decoder
//
//  Created by Kim Seong Jin on 13/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


map<char, int> codes;

void build(){
    char ch = 'A';
    for(int i = 0 ; i < 26 ; i++){
        char newChar = (char)(ch+i);
        codes[newChar] = i;
    }
    
    ch = 'a';
    for(int i = 26 ; i < 52 ; i++){
        char newChar = (char)(ch);
        codes[newChar] = i;
        ch++;
    }
    
    ch = '0';
    for(int i = 52 ; i < 62 ; i++){
        char newChar = (char)(ch);
        codes[newChar] = i;
        
        ch = (char)(ch+1);
    }
    codes['+'] = 62;
    codes['/'] = 63;
}

vector<int>conv6bit(int num){
    vector<int>bit = vector<int>(6, 0);
    int position = 0;
    while(num>0){
        bit[position++] = num%2;
        num/=2;
    }
    reverse(bit.begin(), bit.end());
    return bit;
}

int conv2num(vector<int>bits){
    int pw = pow(2, 7);
    int sum = 0;
    
    for(int i = 0 ; i < 8 ; i++){
        sum += bits[i] * pw;
        pw /= 2;
    }
    
    return sum;
}


void decode(vector<char> chars){
    vector<int>bits;

    int nums[4];
    
    for(int i = 0 ; i < 4 ; i++){
        char ch = chars[i];
        nums[i] = codes[ch];
    }
    
    for(int i = 0 ; i < 4 ; i++){
        int num = nums[i];
        vector<int> bit = conv6bit(num);
        for(int i = 0 ; i < 6 ; i++){
            bits.push_back(bit[i]);
        }
    }
    
    for(int i = 0 ; i < 24 ; i+=8){
        vector<int> bit = vector<int>{bits.begin()+i, bits.begin()+(i+8)};
        cout<<(char)conv2num(bit);
    }
    
}

void solve(int t, string s){
    cout<<"#"<<t<<" ";
    for(int i = 0 ; i < s.size() ; i+=4){
           vector<char> target = vector<char>{s.begin() + i, s.begin()+(i+4) };
           decode(target);
       }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    build();
    int t;
    cin>>t;
    string s;
    for(int i = 0 ; i < t ; i++){
        cin>>s;
        solve(i+1, s);
    }
    
    
    return 0;
}

//0 1 0 0 1 1 0 0    0 1 1 0    1 0 0 1 0 1    1 0 0 1 1 0

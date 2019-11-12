//
//  main.cpp
//  1759_암호만들기
//
//  Created by Kim Seong Jin on 12/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 16

using namespace std;
int len, c;
vector<char> arr;
vector<bool>selected;


void print(){
    int vowels = 0;
    int constants = 0;
    string s;
    for(int i = 0 ; i < c ; i++){
        if(!selected[i])
            continue;
        char c = arr[i];
        s += c;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowels++;
        else
            constants++;
    }
    if(vowels>=1 && constants>=2){
        cout<<s<<endl;
    }
    
}

void comb(int here, int cnt){
    if(cnt==len){

        print();
        return;
    }
   
    for(int there= here ; there < c ; there++){
        if(!selected[there]){
            selected[there] = true;
            comb(there, cnt+1);
            selected[there] = false;
        }
    }
}

void build(){
    arr = vector<char>(c);
    selected = vector<bool>(c, false);
    for(int i = 0 ; i < c; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    //cout<<"BUILD"<<endl;
}

int main(int argc, const char * argv[]) {
    cin>>len>>c;
    build();
    comb(0,0);
    return 0;
}

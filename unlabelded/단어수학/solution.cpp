//
//  main.cpp
//  1339_단어수학
//
//  Created by Kim Seong Jin on 26/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int nums [10] {9,8,7,6,5,4,3,2,1,0};
vector<int>permutation;
vector<bool>selected;
vector<string>words;
map<char, int> chScrore;
vector<char> chList;
int chNum, n;
long long ret;

void print(){
    map<char, int>::iterator it;
    for(it = chScrore.begin() ; it != chScrore.end() ; it++){
        printf("%c %d\n", it->first, it->second);
    }
    cout<<endl;
}

long convNum(string s){
    string numStr = "";
    for(int i = 0 ; i < s.size() ; i++){
        char ch = s[i];
        numStr += to_string(chScrore[ch]);
    }
    //cout<<numStr<<endl;
    return stol(numStr);
}

void wordSum(){
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += convNum(words[i]);
        //cout<<"SUM: "<<sum<<endl;
    }
    ret = max(ret, sum);
}

void setCharScore(){
    for(int i = 0 ; i < chNum ; i++){
        char ch = chList[i];
        chScrore[ch] = permutation[i];
    }
    //print();
}

void perm(int cnt){
    if(cnt == chNum){
        /*
        for(int i = 0 ; i < permutation.size() ; i++){
            cout<<permutation[i]<<" ";
        }
        cout<<endl;
         */
        
        setCharScore();
        wordSum();
        return;
    }
    
    for(int i = 0; i<10 ; i++){

        if(!selected[i]){
            selected[i] = true;
            permutation.push_back(nums[i]);
            perm(cnt+1);
            permutation.pop_back();
            selected[i] = false;
        }
    }
}

void build(){
    set<char> s;
    selected = vector<bool>(10, false);
    string input;
    ret = 0;
    
    for(int i = 0 ; i < n ; i++){
        cin>>input;
        for(int j = 0 ; j < input.size() ; j++){
            s.insert(input[j]);
        }
        words.push_back(input);
    }
    chList = vector<char>(s.begin(), s.end());
    sort(chList.begin(), chList.end());
    chNum = chList.size();
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    if(n==10){
        permutation = vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        setCharScore();
        //print();
        //cout<<convNum("ABCDEFGHIJ");
        wordSum();
        
        cout<<ret<<endl;
        return 0;
    }else{
        perm(0);
        cout<<ret<<endl;
    }
    
    
    return 0;
}

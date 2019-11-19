//
//  main.cpp
//  7568_덩치
//
//  Created by Kim Seong Jin on 19/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

typedef pair<int, int> size;
vector<int>rankes;
vector<size> infos;
int n;

void print(){
    for(int i = 0 ; i < rankes.size() ; i++){
        cout<<rankes[i]<<" ";
    }
    cout<<endl;
}

bool bigger(size a, size b){
    return (a.first < b.first) && (a.second < b.second);
}

void setRank(){
    rankes = vector<int>(n);
    size a, b;
    
    for(int i = 0 ; i < infos.size() ; i++){
        a = infos[i];
        int rank = 1;
        for(int j = 0 ; j < infos.size() ; j++){
            if(i==j)
                continue;
            b = infos[j];
            if(bigger(a, b)){
                rank++;
            }
        }
        rankes[i] = rank;
    }
}

void build(){
    int weight, height;
    infos = vector<size>(n);
    for(int i = 0 ; i < n ; i++){
        cin>>weight>>height;
        infos[i] = size(weight,height);
    }
}

void solve(){
    build();
    setRank();
    print();
}


int main(int argc, const char * argv[]) {
    cin>>n;
    solve();
    return 0;
}

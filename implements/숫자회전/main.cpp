//
//  main.cpp
//  1961_숫자회전
//
//  Created by Kim Seong Jin on 08/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> table;
int n;

void print(vector<table> tables){
    for(int y = 0 ; y <n ; y++){
        for(int idx = 0 ; idx < tables.size() ; idx++){
            for(int x = 0 ; x < tables[idx].size() ; x++){
                cout<<tables[idx][y][x];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

table rotate(table a){
    table b = table(n, vector<int>(n));
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            b[y][x] = a[n-x-1][y];
        }
    }
    return b;
}

table build(){
    table a = table(n, vector<int>(n));
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cin>>a[y][x];
        }
    }
    return a;
}

void solution(int t){
    cin>>n;
    vector<table>tables;
    table a = build();
    
    for(int i = 0 ; i < 3 ; i++){
        table b = rotate(a);
        tables.push_back(b);
        a = b;
    }
    cout<<"#"<<t<<endl;
    print(tables);
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    
    for(int i = 1 ; i<= t; i++){
        solution(i);
    }
    
    return 0;
}

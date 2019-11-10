//
//  main.cpp
//  2005_파스칼삼각형
//
//  Created by Kim Seong Jin on 31/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

void printPascal(int t, int n){
    vector<vector<int>>table (n, vector<int>(n+1, 0));
    table[0][1] = 1;
    for(int row = 1 ; row < n ; row++){
        for(int col = 1; col<=n ; col++){
            table[row][col] = table[row-1][col-1] + table[row-1][col];
        }
    }
    
    cout<<"#"<<t<<endl;
    
    for(int row = 0 ; row< n ; row++){
        for(int col = 1; col<=n ; col++){
            if(table[row][col]){
                cout<<table[row][col]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    int t, n;
    cin>>t;
    for(int i = 1; i<=t ; i++){
        cin>>n;
        printPascal(i, n);
    }
    
    return 0;
}

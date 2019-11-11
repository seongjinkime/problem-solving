//
//  main.cpp
//  2775_부녀회장이될테야
//
//  Created by Kim Seong Jin on 11/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#define MAX 15

using namespace std;

int apt[MAX][MAX];

void init(int n){
    for(int i = 1 ; i<=n ; i++)
        apt[0][i]=i;
}

void solve(int k, int n){
    int row, col;
    init(n);
    
    for(row = 1 ; row<=k ; row++){
        for(col = 1; col<=n ; col++){
            int sum=0;
            for(int k = 1 ; k <= col ; k++){
                sum += apt[row-1][k];
            }
            apt[row][col] = sum;
        }
    }
    cout<<apt[k][n]<<endl;
    
}

int main(int argc, const char * argv[]) {
    int t, k,n;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        cin>>k>>n;
        solve(k, n);
    }
    
    
    return 0;
}

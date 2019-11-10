//
//  main.cpp
//  2001_파리퇴치
//
//  Created by Kim Seong Jin on 31/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>>table;

int getSum(int row, int col, int m){
    int sum = 0;
    
    for(int y = row ; y < row+m ; y++){
        for(int x = col ; x < col+m ; x++){
            //cout<<table[y][x]<<" ";
            sum+=table[y][x];
        }
        //cout<<endl;
    }
    //cout<<endl;
    return sum;
}

void buildTable(int n, int m){
    table = vector<vector<int>> (n, vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>table[i][j];
        }
    }
}

int getMax(int t, int n, int m){
    int res = 0;
    for(int row = 0 ; row + m <= n ; row++){
        for(int col = 0 ; col + m <= n ; col++){
            res = max(res, getSum(row, col, m));
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int t, n, m;
    //n = 7; m = 5;
    //buildTable(n, m);
    //cout<<getSum(0, 0, m)<<endl;
     
    
    vector<int>results;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
        cin>>n>>m;
        buildTable(n, m);
        results.push_back(getMax(t, n, m));
    }
    for(int i = 0 ; i < results.size() ; i++){
        printf("#%d %d\n", i+1, results[i]);
    }
     
    return 0;
}

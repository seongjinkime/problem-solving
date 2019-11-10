//
//  main.cpp
//  11053_가장긴증가하는부분수열
//
//  Created by Kim Seong Jin on 09/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#define MAX 1001


using namespace std;
typedef long long ll;
ll dp[MAX][MAX];
int nums;

void build(int n){
    int input;
    set<int> s;
    for(int i = 0 ; i < n ; i++){
        cin>>input;
        s.insert(input);
    }
    nums = s.size();
    for(int i = 0 ; i < nums ; i++){
        dp[1][i] = 1;
        
    }
    
}

void solution(){
    int n;
    ll rowSum;
    int row = 2;
    rowSum = nums;
    cin>>n;
    build(n);
    
    while(row<=n){
        
        rowSum = 0;
        for(int current = 0 ; current<nums ; current++){
            ll sum = 0;
            for(int walker = current+1 ; walker<nums ; walker++){
                sum += dp[row-1][walker];
            }
            dp[row][current] = sum;
            rowSum+=sum;
        }
        if(rowSum==0)break;
        row++;
    }
    cout<<row-1<<endl;
}





int main(int argc, const char * argv[]) {
    solution();
    return 0;
}

//
//  main.cpp
//  2143_두배열의합(retry)
//
//  Created by Kim Seong Jin on 2019. 12. 30..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
vector<int> subsA, subsB;

void solve(){
    long long cnt = 0;
    sort(subsA.begin(), subsA.end());
    sort(subsB.begin(), subsB.end());
    
    for(int i = 0 ; i < subsA.size() ; i++){
        int diff = t - subsA[i];
        auto ub = upper_bound(subsB.begin(), subsB.end(), diff);
        auto lb = lower_bound(subsB.begin(), subsB.end(), diff);
        cnt += (ub-lb);
    }
    cout<<cnt<<endl;
}

void build(){
    int n, m;
    int sum;
    vector<int> numsA, numsB;
    cin>>n;
    numsA = vector<int>(n);
    
    for(int i = 0; i < n ; i++)
        cin>>numsA[i];
    
    cin>>m;
    numsB = vector<int>(m);
    for(int i = 0 ; i < m ; i++)
        cin>>numsB[i];
    
    
    
    for(int i = 0 ; i < n ; i++){
        sum = 0;
        for(int j = i ; j < n ; j++){
            sum += numsA[j];
            subsA.push_back(sum);
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        sum = 0;
        for(int j = i ; j < m ; j++){
            sum += numsB[j];
            subsB.push_back(sum);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin>>t;
    build();
    solve();
    return 0;
}

//
//  main.cpp
//  2003_수들의합2(retry)
//
//  Created by Kim Seong Jin on 2019. 12. 27..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n, m;

int solve(){
    int cnt = 0;
    int sum = arr[0];
    int i, j;
    i = j = 0;
    
    while (i < n && j < n ) {
        if(sum < m){
            sum += arr[++i];
        }else if(sum == m){
            cnt++;
            sum += arr[++i];
        }else if(sum > m){
            sum -= arr[j++];
            if(i < j){
                sum = arr[j];
                i = j;
            }
        }
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    arr = vector<int>(n);
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }
    cout<<solve()<<endl;
    return 0;
}

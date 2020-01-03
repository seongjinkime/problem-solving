//
//  main.cpp
//  1644_소수의연속합
//
//  Created by Kim Seong Jin on 2019. 12. 16..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4000001

using namespace std;
bool isPrime[MAX];
vector<int> primes;
int n;


void solve(){
    int low, high;
    int sum;
    int cnt = 0;
    low = high = 0;
    sum = primes[0];
    while(low <= high && high<primes.size()){
        if(sum<n){
            high++;
            sum += primes[high];
        }else if(sum==n){
            cnt++;
            high++;
            sum += primes[high];
        }else if(sum>n){
            sum -= primes[low];
            low++;
            if(low > high && low<primes.size()){
                high = low;
                sum = primes[low];
            }
        }
    }
    cout<<cnt<<endl;
    
}

void build(){
    //erots
    
    for(int i = 1 ; i <= n ; i++)
        isPrime[i] = true;
    
    for(int i = 2; i * i <= n ; i++){
        if(isPrime[i]){
            for(int j = i*i ; j<=n ; j+=i){
                isPrime[j] = false;
            }
        }
    }
    
    for(int i = 2 ; i <= n ; i++){
        if(isPrime[i]){
            primes.push_back(i);
            //cout<<i<<" ";
        }
    }
    //cout<<endl;
}


int main(int argc, const char * argv[]) {
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
        
    build();
    solve();
    return 0;
}

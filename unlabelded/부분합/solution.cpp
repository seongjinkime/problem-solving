//
//  main.cpp
//  1806_부분합
//
//  Created by Kim Seong Jin on 2019. 12. 16..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

vector<int>arr;
int n,s;
int ret;


void solve(){
    int low, high;
    int sum;
    
    low = high = 0;
    sum = arr[0];
    
    while(low<=high && high<n){
        if(sum<s){
            high++;
            sum += arr[high];
        }else if(sum == s){
            ret = min(ret, high-low + 1);
            high++;
            sum += arr[high];
        }else if(sum > s){
            ret = min(ret, high-low+1);
            sum -= arr[low];
            low++;
            if(low>high && low<n){
                high = low;
                sum = arr[high];
            }
        }
    }
    
    if(ret == INF){
        cout<<0<<endl;
    }else{
        cout<<ret<<endl;
    }
}

void build(){
    ret = INF;
    arr = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }
}

int main(void){
    scanf("%d %d", &n, &s);
    build();
    solve();
    
    return 0;
    
}


/*

void partial(vector<int>& arr, int left, int right){
    if(left == right){
        if(arr[left] >= s){
            ret = min(ret, 1);
        }
        return;
    }
    int mid = (left+right) / 2;
    int sum = 0;
    int len = 0;
    
    for(int i = mid ; i >= left ; i--){
        sum += arr[i];
        len++;
        if(sum>=s){
            ret = min(ret, len);
            break;
        }
    }
    sum = 0;
    len = 0;
    for(int i = mid+1 ; i<= right ; i++){
        sum += arr[i];
        len++;
        if(sum>=s){
            ret = min(ret, len);
            break;
        }
    }
    
    partial(arr, left, mid);
    partial(arr, mid+1, right);
}

vector<int>build(){
    ret = INF;
    vector<int> nums = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &nums[i]);
    }
    return nums;
}

int main(void){
    scanf("%d %d", &n, &s);
    vector<int> arr = build();
    partial(arr, 0, n-1);
    if(ret==INF){
        cout<<0<<endl;
    }else{
        cout<<ret<<endl;
    }
    
}
 */
/*
 10 15
 5 1 3 15 10 7 4 9 2 8
 */

/*
vector<int> arr;
int n, s;
int ret;

void dfs(int sum, int len, int idx){
    if(idx >= n)
        return;
    if(sum >= s){
        ret = min(ret, len);
        return;
    }
    
    dfs(sum + arr[idx+1], len + 1, idx+1);
    
}

void solve(){
    for(int i = 0 ; i < n ; i++){
        dfs(arr[i], 1, i);
    }
    if(ret == INF){
        cout<<0<<endl;
    }else{
        cout<<ret<<endl;
    }
    
}

void build(){
    arr = vector<int>(n);
    ret = INF;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i];
        if(arr[i]>=s){
            cout<<1<<endl;
            exit(0);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    cin>>n>>s;
    build();
    solve();
    
    return 0;
}
*/

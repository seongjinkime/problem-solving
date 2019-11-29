//
//  main.cpp
//  10942_팰린드롬?
//
//  Created by Kim Seong Jin on 2019. 11. 28..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 2001
using namespace std;

bool table[MAX][MAX];
vector<int>nums;
int n, m;

bool palindrome(vector<int> arr){
    vector<int> rev (arr.rbegin(), arr.rend());
    return arr==rev;
}

void build(){
    nums = vector<int>(n+1, 0);
    vector<int> part;
    for(int i = 1 ; i <= n ; i++){
        //cin>>nums[i];
        scanf("%d", &nums[i]);
    }
    for(int s = 1 ; s<=n ; s++){
        for(int e = s ; e<=n ; e++){
            part = vector<int> (nums.begin()+s, nums.begin()+e+1);
            table[s][e] = palindrome(part);
            //printf("%d - %d : %d\n", s, e, table[s][e]);
        }
    }
}

void solve(){
    int s, e;
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d", &s, &e);
        //cin>>s>>e;
        printf("%d\n", table[s][e]);
        //cout<<table[s][e]<<endl;
    }
}

int main(int argc, const char * argv[]) {
   
    cin>>n;
    build();
    cin>>m;
    solve();
    return 0;
}

/*
 #include <iostream>
 #include <vector>
 #define MAX 2001
 using namespace std;
 
 //bool table[MAX][MAX];
 vector<int> table [MAX][MAX];
 vector<int>nums;
 int n, m;
 
 bool palindrome(vector<int> arr){
 vector<int> rev (arr.rbegin(), arr.rend());
 return arr==rev;
 }
 
 void build(){
 nums = vector<int>(n+1, 0);
 //table = vector<vector<vector<int>>>(n+1, n+1, vector<int>());
 vector<int> part, rev;
 for(int i = 1 ; i <= n ; i++){
 cin>>nums[i];
 }
 for(int s = 1 ; s<=n ; s++){
 for(int e = s ; e<=n ; e++){
 part = vector<int> (nums.begin()+s, nums.begin()+e+1);
 rev = vector<int> (part.rbegin(), part.rend());
 table[s][e] = part;
 table[e][s] = rev;
 
 //table[s][e] = palindrome(part);
 //printf("%d - %d : %d\n", s, e, table[s][e]);
 }
 }
 }
 
 void solve(){
 int s, e;
 for(int i = 0 ; i < m ; i++){
 cin>>s>>e;
 cout<<(table[s][e] == table[e][s])<<endl;
 //cout<<table[s][e]<<endl;
 }
 }
 
 int main(int argc, const char * argv[]) {
 
 cin>>n;
 build();
 cin>>m;
 solve();
 return 0;
 }
 */

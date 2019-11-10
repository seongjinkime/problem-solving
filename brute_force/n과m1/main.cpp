//
//  main.cpp
//  15649_n과m1
//
//  Created by Kim Seong Jin on 07/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int>num;
vector<int>arr;
vector<bool>select;
int n, m;

void print(){
    for(int i = 0 ; i < num.size() ; i++)
        cout<<num[i]<<" ";
    cout<<endl;
}

void permutaion(int cnt){
    if(cnt==m){
        print();
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(!select[i]){
            select[i]=true;
            num.push_back(arr[i]);
            permutaion(cnt+1);
            num.pop_back();
            select[i]=false;
        }
    }
}

void build(){
    arr = vector<int>(n);
    select = vector<bool>(n);
    for(int i = 1 ; i <= n ; i++){
        arr[i-1]=i;
    }
}

int main (int argc, const char * argv[]){
    cin>>n>>m;
    build();
    permutaion(0);
    return 0;
}

/*

void solution(int n, int m){
    int arr[n];
    
    for(int i = 1; i <=n ; i++)
        arr[i-1]=i;
    
    for(int walker = 1; walker<n ; walker++){
        for(int pivot = 1 ; pivot<n ; pivot++){
            if(pivot+m+1 >n)continue;
            for(int checker = pivot ; checker<pivot+m ; checker++){
                printf("%d %d\n", arr[0], arr[checker]);
            }
        }
        swap(arr[0], arr[walker]);
    }
    return;
}


int main(void){
    int n, m;
    cin>>n>>m;
    solution(n, m);
    
}
*/

/*

vector<int> mkArr(int n){
    vector<int>arr;
    for(int i = 1 ; i <= n ; i++)
        arr.push_back(i);
    return arr;
}

void print(vector<int> arr, int m){

    do{
        for(int i = 0 ; i < m ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(arr.begin(), arr.begin()+m));
    //cout<<endl;
}



void solution(int n, int m){
    vector<int>arr = mkArr(n);
    print(arr, m);
    return;
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    solution(n,m);
    return 0;
}
*/


/*
vector<char>candiates;
void build(int n){
    candiates = vector<char>();
    for(int i = 1 ; i <=n ; i++){
        candiates.push_back((char)'0'+i);
    }
}

bool validate(int num){
    string s = to_string(num);
    int sum = 0;
    for(int i = 0 ; i < candiates.size() ; i++){
        int cnt = count(s.begin(), s.end(), candiates[i]);
        if(cnt > 1) return false;
        sum+=cnt;
    }
    if(sum==0 || sum != s.size())
        return false;
    else
        return true;
}

void print(int num){
    string s = to_string(num);
    for(char c : s)
        cout<<c<<" ";
    cout<<endl;
}


void solution(int n, int m){
    build(n);
    int num = 1;
    int limit = 9;
    for(int i = 1 ; i < m ; i++){
        num*=10;
        limit = limit*10+9;
    }
    //cout<<num<<" "<<limit<<endl;
    while(num<=limit){
        if(validate(num)){
            print(num);
        }
        num++;
    }
    
    //cout<<num<<endl;
}
 */



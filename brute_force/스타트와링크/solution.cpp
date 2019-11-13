//
//  main.cpp
//  14889_스타트와링크
//
//  Created by Kim Seong Jin on 13/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#define INF 987654321
#define MAX 21

using namespace std;

vector<int>permutation;
vector<bool>selected;

vector<bool>visited;
vector<int>nums;

int table[MAX][MAX];
int n, ret;
set<string>s;

int score(vector<int> members){
    int sum = 0;
    int pa, pb;
    
    for(int i = 0 ; i < members.size() ; i++){
        pa = members[i];
        for(int j = 0 ; j < members.size() ; j++){
            if(i==j)
                continue;
            pb = members[j];
            sum += table[pa][pb];
        }
    }
    return sum;
}

string getStr(){
    string str="";
    for(int p : permutation)
        str += to_string(p);
    return str;
}

bool isExist(string str){
    if(s.count(str) > 0)
        return true;
    reverse(str.begin(), str.end());
    if(s.count(str) > 0)
        return true;
    
    return false;
}


int compare(){
    string pstr = getStr();
    if (isExist(pstr))
        return -1;
    
    vector<int> teamA = vector<int>(permutation.begin(), permutation.begin()+n/2);
    vector<int> teamB = vector<int>(permutation.begin()+(n/2), permutation.end());
    
    int scoreA = score(teamA);
    int scoreB = score(teamB);
    
    s.insert(pstr);
    
    return abs(scoreA-scoreB);
}

void dfs(int cnt){
    if(cnt == n){
        int diff = compare();
        if(diff == -1){
            return;
        }
        ret = min(ret, diff);
        return;
    }
    for(int i = 1; i<= n ;i++){
        if(!selected[i]){
            selected[i]=true;
            permutation.push_back(nums[i]);
            dfs(cnt+1);
            permutation.pop_back();
            selected[i] = false;
        }
    }
}



void build(){
    
    nums = vector<int>(n+1);
    selected = vector<bool>(n+1, false);
    for(int i = 1 ; i <= n ; i++){
        nums[i] = i;
    }
    
    for(int y = 1 ; y <= n ; y++){
        for(int x = 1 ; x <= n ; x++){
            cin>>table[y][x];
        }
    }
    ret = INF;
}

int main(int argc, const char * argv[]) {
    cin>>n;
    build();
    dfs(0);
    cout<<ret<<endl;
    return 0;
}

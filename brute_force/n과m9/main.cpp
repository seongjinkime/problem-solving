#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int>nums;
vector<int>permutation;
set<vector<int>>s;
vector<bool>selected;
int n,m;

void print(){
    if(s.count(permutation)>0)
        return;
        
    for(int i = 0 ; i < permutation.size() ; i++){
        printf("%d ", permutation[i]);
    }
    s.insert(permutation);
    printf("\n");
}

void dfs(int cnt, int start){
    if(cnt==m){
        print();
        return;
    }
    for(int i = start ; i < n ; i++){
        
        selected[i] = true;
        permutation.push_back(nums[i]);
        dfs(cnt+1, i);
        permutation.pop_back();
            
        
    }
}

void build(){
    nums = vector<int>(n);
    selected = vector<bool>(n);
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    build();
    dfs(0, 0);
    
    return 0;
}


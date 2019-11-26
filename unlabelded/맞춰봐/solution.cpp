#include <iostream>
#include <vector>
#include <string>

#define MAX 11

using namespace std;
vector<vector<char>> op;
vector<bool> selected;
vector<int> nums;
vector<int>permutation;
int n;


bool qualified(int col){
    int sum = 0;
    int idx = col;
    for(int row = col ; row >= 0 ; row--){
        sum += permutation[idx];
        if(op[row][col] == '+' && sum <= 0)
            return false;
        if(op[row][col] == '-' && sum >= 0)
            return false;
        if(op[row][col] == '0' && sum != 0)
            return false;
        idx--;
    }
    return true;
}

void perm(int cnt){
    if(cnt == n){
        for(int i = 0 ; i < permutation.size() ; i++){
            cout<<permutation[i]<<" ";
        }
        exit(0);
        
    }
    for(int i = 0 ; i < nums.size() ; i++){
        permutation.push_back(nums[i]);
        if(qualified(cnt)){
            perm(cnt+1);
        }
        permutation.pop_back();
    }
}

void build(){
    nums = vector<int>(21);
    selected = vector<bool>(21, false);
    op = vector<vector<char>>(n, vector<char>(n));
    int num = -10;
    for(int i = 0; i < 21 ; i++){
        nums[i] = num;
        num++;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            cin>>op[i][j];
        }
    }
}



int main(int argc, const char * argv[]) {
    
    cin>>n;
    build();
    perm(0);

    return 0;
}

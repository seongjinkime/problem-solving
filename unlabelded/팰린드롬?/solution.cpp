#include <iostream>
#include <vector>
#define MAX 2001
using namespace std;

bool palindrome[MAX][MAX];
vector<int>nums;
int n, m;

void preCheck(){
    int s, e;
    //len = 1
    for(s = 0 ; s < n ; s++){
        palindrome[s][s] = 1;
    }
    //len = 2
    for(int s = 0 ; s < n-1 ; s++){
        e = s+1;
        if(nums[s] == nums[e]){
            palindrome[s][e] = 1;
        }
    }
    
    //len > 3
    for(int len = 2 ; len < n ; len++){
        for(s = 0 ; s < n-len ; s++){
            e = s + len;
            if(nums[s] == nums[e] && palindrome[s+1][e-1]){
                palindrome[s][e] = true;
            }
        }
    }
}

void build(){
    nums = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &nums[i]);
    }
}

void solve(){
    scanf("%d", &m);
    int s, e;
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", palindrome[s-1][e-1]);
    }
}

int main(void){
    scanf("%d", &n);
    build();
    preCheck();
    solve();
    
}

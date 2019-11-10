
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> picA, picB;
int n;

void dfs(vector<vector<int>>& table, int num, int y, int x){
    table[y][x] = 0;
    if(y>0 && table[y-1][x] == num)
        dfs(table, num, y-1, x);
    if(y<n-1 && table[y+1][x] == num)
        dfs(table, num, y+1, x);
    if(x>0 && table[y][x-1] == num)
        dfs(table, num, y, x-1);
    if(x<n-1 && table[y][x+1] == num)
        dfs(table, num, y, x+1);
}

void build(){
    picA = picB = vector<vector<int>>(n, vector<int>(n, 0));
    char in;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>in;
            switch (in) {
                case 'R':
                    picA[i][j] = 1;
                    picB[i][j] = 1;
                    break;
                case 'G':
                    picA[i][j] = 2;
                    picB[i][j] = 1;
                    break;
                case 'B':
                    picA[i][j] = 3;
                    picB[i][j] = 2;
                    break;
            }
        }
    }
}

void solution(int input){
    n = input;
    build();
    int cntA, cntB;
    cntA=cntB=0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            if(picA[y][x]!=0){
                dfs(picA, picA[y][x], y, x);
                cntA++;
            }
            if(picB[y][x]!=0){
                dfs(picB, picB[y][x], y, x);
                cntB++;
            }
        }
    }
    cout<<cntA <<" "<<cntB;
}



int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    solution(n);
    return 0;
}

/*
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
 */

#include <iostream>
#include <vector>
#define MAX 15

using namespace std;

int board[MAX][MAX];
int n, num;


bool possible(int y, int x){
    for(int ny = y, nx = x; ny>=0&&nx>=0 ; ny--, nx--){
        if(board[ny][nx] == 1)
            return false;
    }
    
    for(int ny = y, nx = x; ny>=0&&nx<n ; ny--, nx++){
        if(board[ny][nx] == 1)
            return false;
    }
    
    for(int ny = y, nx = x; ny>=0&&nx>=0 ; ny--){
        if(board[ny][nx] == 1)
            return false;
    }
    return true;
}


void drop(int y){
    if(y == n){
        num+=1;
        return;
    }
    
    for(int x = 0; x < n ; x++){
        if(possible(y, x)){
            board[y][x] = 1;
            drop(y+1);
            board[y][x] = 0;
        }
    }
}


int main(int argc, const char * argv[]) {
    num = 0;
    cin>>n;
    //board[0][0] = 1;
    drop(0);
    cout<<num<<endl;
    
    return 0;
}

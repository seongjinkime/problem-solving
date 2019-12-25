![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2580.png)
[문제 바로가기](https://www.acmicpc.net/problem/2580)
### Type : 브루트포 + 백트랙킹

#### 접근
1. 빈 칸을 채워 나갈때 존건에 부합하는지 검사 한다 (퇴각 검사)
    - 가로 및 세로 줄의 모든 숫자는 중복없이 고유 해야 한다
    - 위치에 속한 3x3 영역 내의 숫자도 중복없이 고유 해야 한다.

2. 위치 판별  
    - y와 x를 각각 3으로 나눈다 => 0, 1, 2 중 하나의 숫자가 나온다
    - 영역 시작 점 = 3 * 몫
    - 영역 종료 점 = 3 * (몫+1)  

3. 완전 탐색 및 종료  
    - 조건에 부합하는 모든 수를 채우면 테이블을 출력하고 종료 한다.  


3. 플로우 차트  

빈칸에 채워질 숫자가 고유한지 검사하는 isUnique  
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2580_isUnique.png)



#### 구현 코드



```cpp
#include <iostream>
#include <vector>

using namespace std;

int table[9][9];
vector<vector<int>> emptyPoints;


bool isUnique(int y, int x, int num){
    int py, px;
    int sy, dy, sx, dx;

    for(int col = 0 ; col < 9 ; col++){
        if(col!=x && table[y][col] == num)
            return false;
    }

    for(int row = 0 ; row < 9 ; row++){
        if(row!=y && table[row][x] == num)
            return false;
    }

    py = y/3;
    px = x/3;

    sy = 3 * py;
    dy = 3 * (py+1);

    sx = 3 * px;
    dx = 3 * (px+1);

    for(int i = sy ; i < dy ; i++){
        for(int j = sx ; j < dx ; j++){
            if(i == y && j == x)
                continue;
            if(table[i][j] == num)
                return false;
        }
    }

    return true;
}

void print(){
    for(int y = 0 ; y < 9 ; y++){
        for(int x = 0 ; x < 9 ; x++){
            cout<<table[y][x]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

void insert(int cnt){
    if(cnt == emptyPoints.size()){
        print();
        exit(0);
    }

    int y = emptyPoints[cnt][0];
    int x = emptyPoints[cnt][1];

    for(int num = 1 ; num < 10 ; num++){
        if(isUnique(y, x, num)){
            table[y][x] = num;
            insert(cnt+1);
            table[y][x] = 0;
        }
    }
}

void build(){
    for(int y = 0 ; y < 9 ; y++){
        for(int x = 0 ; x < 9 ; x++){
            cin>>table[y][x];
            if(table[y][x] == 0){
                emptyPoints.push_back({y, x});
            }
        }
    }


}

int main(int argc, const char * argv[]) {
    build();
    //cout<<emptyCnt<<endl;
    insert(0);
    return 0;
}


```

### 깨달은 점
1. 퇴각 검사를 실시하여 완전탐색 시간을 줄일 수 있다.  

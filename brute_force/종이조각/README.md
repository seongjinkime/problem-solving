![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/14391.png)
[문제 바로가기](https://www.acmicpc.net/problem/14391)
### Type : 브루트포스

#### 접근
1. 상태를 2가지로 나눈다.
(1) 번호가 선택된 상태
(2) 번호가 선택되지 않은 상태   

2. 깊이 우선 탐색을 통해 각 행별로 숫자를 선택한다.
(1) 숫자를 선택해나가며 깊이 우선 탐색을 실시한다.  
(2) 선택을 해재한 뒤로 다시 깊이 우선 탐색을 실시한다.
(3) 연속된 재귀함수로 가능한 모든 분할의 경우를 만들어 낸다.
    ```
    T T T T T
    T T T T F
    T T T F T
    T T T F F
    T T F T T
    T T F T F
    T T F F T
    T T F F F
    ...
    ```

3. 가로, 세로 별로 종이에 적힌수를 합산한다.

#### 주요 포인트  
  - **x >= m 일때 x를 0으로 만들고 y를 증가 시킨다**
  - **반복문 없이 x+1, y+1을 통해 조합을 만들어 낸다**
  - **재귀안의 재귀를 만들어 부가적인 경우의수를 만든다**


### 플로우 차트
1.  종이조각을 나누기 위한 깊이 우선 탐색  
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/14391_dfs.png)
2.  합계를 위한 sum
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/14391_sum.png)

#### 구현 코드

```cpp
#include <iostream>
#define MAX 5
using namespace std;

int table [MAX][MAX];
bool selected[MAX][MAX];

int n, m;
int ret;

int sum(){
    int total = 0;
    int sum;
    for(int row = 0 ; row < n ; row++){
        sum = 0;
        for(int col = 0 ; col < m ; col++){
            if(selected[row][col]== true){
                sum = (sum * 10) + table[row][col];
            }else{
                total += sum;
                sum = 0;
            }
        }
        total += sum;
    }

    for(int col = 0 ; col < m ; col++){
        sum = 0;
        for(int row = 0 ; row < n ; row++){
            if(selected[row][col] == false){
                sum = (sum * 10) + table[row][col];
            }else{
                total += sum;
                sum = 0;
            }
        }
        total += sum;
    }
    return total;


}

void dfs(int y, int x){
    if(y == n){
        ret = max(ret, sum());
        return;
    }

    if(x == m){
        dfs(y+1, 0);
        return;
    }

    selected[y][x] = true;
    dfs(y, x+1);
    selected[y][x] = false;
    dfs(y, x+1);
}

void build(){
    ret = 0;
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%1d", &table[i][j]);
        }
    }
}

int main(int argc, const char * argv[]) {
    build();
    dfs(0, 0);
    cout<<ret<<endl;
    return 0;
}

```

### 깨달은 점
1. 재귀안의 재귀를 통해 부가적인 경우의 수를 만들 수 있다.

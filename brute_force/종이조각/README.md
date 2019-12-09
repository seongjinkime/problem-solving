![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/14391.png)
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

#### 구현 코드

```cpp
#include <iostream>
#include <vector>
#define MAX 5
using namespace std;
int table[MAX][MAX];
bool selected[MAX][MAX];
int n, m;
int ret;

//가로 합산
int sumOfHorizon(){
    int num, sum;
    sum = 0;
    //세로
    for(int y = 0 ; y < n ; y++){
        num = 0;
        //가로
        for(int x = 0 ; x < m ; x++){
            if(selected[y][x]==1){
                num = (num * 10) + table[y][x]; //만약 종이가 이어져 있다면 수를 더한다
            }else{
                sum += num;
                num = 0; //그렇지 않다면 이전의 수를 더하고 0으로 초기화 한다.
            }
        }
        sum += num; //마지막 행의 수를 더한다.
    }
    return sum;
}
//세로 합산 (가로와 동일)
int sumOfVertical(){
    int num, sum;
    sum = 0;
    //가로
    for(int x = 0 ; x < m ; x++){
        num = 0;
        //세로
        for(int y = 0 ; y < n ; y++){
            if(selected[y][x]==0){
                num = (num * 10) + table[y][x];
            }else{
                sum += num;
                num = 0;
            }
        }
        sum += num;
    }
    return sum;
}
//접근 3. 가로, 세로 합산
void sum(){
    int sum;
    sum = sumOfHorizon() + sumOfVertical();
    ret = max(ret, sum);
}

//접근 2. 모든 분할의 경우의 수를 만들기
void dfs(int y, int x){
    //모든 행을 탐색 한 뒤 합산 시작
    if(y >= n){
        sum();
        return;
    }
    //주요 포인트 1. 모든 열을 검사 했을때 x를 0으로 만들고, y를 증가 시킨다.
    if(x >= m){
        dfs(y+1, 0);
        return;
    }

    //주요 포인트 2. 반복문 없이 x+1, y+1을 통해 조합을 만들어냄
    selected[y][x] = true;
    dfs(y, x+1);
    selected[y][x] = false;
    //주요 포인트 3. 재귀안에 재귀를 만들어 부가적인 경우의 수를 만들어냄
    dfs(y, x+1);

}

void build(){
    ret = 0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            scanf("%1d", &table[y][x]);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    //입력 및 초기화
    build();
    //조합 생성 및 합산
    dfs(0, 0);
    //결과 출력
    cout<<ret<<endl;
    return 0;
}

```

### 깨달은 점
1. 재귀안의 재귀를 통해 부가적인 경우의 수를 만들 수 있다.
2. 상태를 정하면서 탐색을 진행할 수 있다.

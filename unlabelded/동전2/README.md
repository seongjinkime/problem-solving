![Problem](https://github.com/seongjinkime/problem-solving/raw/master/images/2294.png)
### Type : Dynamic Programming

#### 접근
1.  주요 방식
(1) 메모이제이션을 활용한 탐색
(2) 1원 부터 k원까지 최소한의 동전수를 구해나간다
(3) money를 만들기 위해 한 종류의 동전을 n개 사용했을때 최소값이 되는지 확인한다
(4) dp[money] = min(dp[money], dp[money - (coin * n)] + n)

<br>

2. 초기화
(1) 모든 배열의 값을 INF 로 초기화 한다
(2) 동전의 가치 (value)가 주어졌을때, 가치 만큼의 돈은 동전 1개로 만들 수 있다.    
    - 10원의 동전이 주어진다면 10원은 동전 1개로 만들 수 있다

<br>

3. 탐색
(1) 1원부터 k원까지 진행한다
(2) 각각의 동전을 탐색 한다
(3) 만약 구하고자 하는 돈보다 동전의 가치가 크다면 pass 한다
(4) 동전 * 갯수 < money 일때까지 탐색을 진행 한다
(5) [money - (동전*갯수)] + 갯수 를 통해 최소한의 동전수를 구한다
    - (동전*갯수)가 빠진 만큼을 DP 배열에서 구한다
    - 곱한 갯수 만큼을 더해준다

#### 구현 코드

```cpp
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 101
#define INF 987654321

using namespace std;
typedef long long LL;
int dp[100001];
int coins[101];
int n, k;

int solve(int n){
    //접근 1-1. 모든 배열의 값을 INF로 초기화
    for(int i = 0 ; i <= k ; i++)
        dp[i] = INF;
    //접근 1-2. 동전 1개로 만들 수 있는 돈을 1로 초기화
    for(int i = 0 ; i< n ; i++){
        dp[coins[i]] = 1;
    }

    //접근 2 탐색
    for(int money = 1 ; money<= k ; money++){
        for(int idx = 0 ; idx < n ; idx++){
            int coin = coins[idx];
            if(coin>money) continue;
            for(int cnt = 1 ; cnt*coin < money ; cnt++){
                dp[money] = min(dp[money], dp[money-(cnt*coin)]+cnt);
            }
        }
    }


    return dp[k];
}

void build(){
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i];
    }
}


int main(int argc, const char * argv[]) {
    //입력
    cin>>n>>k;
    build();
    //문제 해결 진행
    int ret = solve(n);

    if(ret == INF){
        cout<<-1<<endl; //만약 주어진 동전으로 돈을 만들 수 없다면 -1
    }else{
        cout<<ret<<endl; //최소한의 동전 수 출력
    }


    return 0;
}


```

### 깨달은 점
1. 메모이제이션을 활용한 탐색 방식으로 Dynamic Programming 문제를 풀 수 있다.

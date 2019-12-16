![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/15988.png)
[문제 바로가기](https://www.acmicpc.net/problem/15988)
### Type : Dynamic Programming

#### 접근
1. 재귀 탐색만으로는 시간 초과가 발생 하는 문제이다. 접근을 달리하여 완전 동적 계획법으로 문제를 풀어야 한다.

#### 주요 포인트
1. 함수의 배열화
  - 함수의 배열화란 예상되는 함수의 결과값을 배열에 미리 저장해두어 계산해나가는 방식을 말한다.
  - 주로 Bottom UP 방식에서 활용 된다.
  - 이번 문제처럼 재귀트리가 무수히 많이 발생하는 경우에는 작은 값부터 배열을 채워나가는게 효율적이다.
    - 100 만번 * 3 => 1초이내 해결가능

2. 함수의 배열화 응용  
  - 1, 2, 3 더하기를 좀 더 깊이 생각해보면 숫자 n을 만드는 경우의 수는 갯수(n-1) + 갯수(n-2) + 갯수(n-3) 과 같다
  - 1로 시작 하면서 n을 만드는 경우
  - 2로 시작 하면서 n을 만드는 경우
  - 3으로 시작하면서 n을 만드는 경우
  *재귀 호출에서 f(n+1) + f(n+2) + f(n+3) 과 같은 경우라 보면 된다.*

3. 점화식 도출  
  - dp[n] = dp[n-1] + dp[n-2] + dp[n-3]

4. 오버플로우 방지  
  - 문제에 주어진 대로 배열의 값은 항상 값의 나머지로 저장 한다
  - 배열의 타입을 long long 으로 선언한다.



#### 구현 코드



```cpp

#include <iostream>
#define mod 1000000009
#define LL long long
#define MAX 1000001


using namespace std;
LL arr[MAX];

//배열에 경우의 수를 저장, 최초 1회만 실행
void init(){
    //배열값 초기화
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    //최대값 까지 경우의 수 저장
    for(int i = 4 ; i <= MAX ; i++){
        for(int j = 1 ; j<=3 ; j++){
            arr[i] += arr[i-j];
        }
        arr[i] = arr[i] % mod;
    }
}

int main(int argc, const char * argv[]) {
    int t,n;
    init();
    cin>>t;
    //배열의 값을 출력 하기만 한다.
    for(int i = 0 ; i < t ; i++){
        cin>>n;
        cout<<arr[n]<<endl;
    }
    return 0;
}



```

### 깨달은 점
1. 함수의 배열화를 통해 시간을 줄일 수 있다.
2. 함수의 배열화에선 작은값부터 서서히 채워 나가는 Bottom up 방식을 사용한다.
    - 기존의 값을 활용하는 방식
    -(n+1)(x) (n-1)(o)

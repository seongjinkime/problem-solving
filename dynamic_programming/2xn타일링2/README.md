![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/11727.png)
### Type : Dynamic Programming

#### 나의 문제점
1. 점화식을 세우는 원리를 이해하지 못했다  
2. 종류별로 경우의 수를 나누어 식을 세운다...? 정도만 이해한 채로 다른 문제에 접근하려니 풀리지 않았다

#### DP를 처음 부터 다시 
1. DP의 Hello World 격인 타일링 문제를 점화식이 아닌 프로그래밍적으로 접근하는 강의를 듣게 되었다.
2. DFS로 DP 문제에 접근하는 것을 보고 가물가물 했던 개념을 잡을 수 있었다.

#### 2xn 타일링 2
1. 2xn 타일을 채우기 위한 타일의 종류는 총 3가지가 있다.
```
 a) 2 X 1   
 b) 1 X 2  
 c) 2 X 2  
```
2.  n을 1씩 증가시키며 그림을 그려본다
![Tree](https://github.com/seongjinkime/problem-solving/blob/master/images/11727_tree.png)

3. 예시
```
n이 3일 경우
1) 모양이 2 x 1로 시작할 때 2 x 2 모양의 타일을 붙일 수 있다
2) 모양이 1 x 2로 시작할 때 2 x 1 모양의 타일을 붙일 수 있다
3) 모양이 2 x 2로 시작할 때 2 x 1 모양의 타일을 붙일 수 있다
```

4. 자연수 n으로 일반적인 규칙을 세워 본다
```
1) 2 x n-2로 시작할 때 2 x n-1 모양의 타일을 붙일 수 있다
2) 2 x n-1로 시작할 때 2 x n-2 모양의 타일을 붙일 수 있다
3) 2 x n-1로 시작할 때 2 x n-2 모양의 타일을 붙일 수 있다
```

5. 이를 탐색하는 과정을 DFS 로 설계할 수 있다
```cpp
int dfs(int n){
    if(n<=1)
        return 1;
    
    return dfs(n-1) + dfs(n-2) + dfs(n-2);
}
```
DFS 함수가 트리와 같이 경우의 수를 계산해나가기 때문에 답이 도출 될 수 있다.  
하지만 여기서 문제가 발생한다.
```
Problem 1 ) dfs 콜수가 무한정 늘어난다. 
Problem 2 ) n이 커질경우 int 형 범위를 벗어난다.
```
6. Memoization  
dfs (n-1), dfs(n-2), dfs(n-2) 를 계산하면서 분명 같은 값을 중복해서 계산 할 것이다.  
계산하는 결과를 미리 저장하여 Return 한다면 계산 횟수를 줄일 수 있다.
```cpp
int dfs(int n){
    if(n<=1)
        return 1;
    
    if(dp[n] == 0){
        int ret = (dfs(n-1) + dfs(n-2) + dfs(n-2)) % 10007;
        dp[n] = ret;
        return ret;
    }
    
    return dp[n];
}
```
Problem 2를 해결하기 위하여 정수 10007을 나누어 값의 범위를 낮춘다.


7. 함수의 배열화
Dynamic Programming 은 DFS 와 같은 함수를 배열로 표현하는 것이 가장 큰 특징이다.
여기서 사용할 방법은 Bottom UP 이다.

Bottom UP은 배열의 값을 처음부터 빼곡히 채워나가는 방법을 말한다.
즉 "dfs(n-1) + dfs(n-2) + dfs(n-2)"을 0~n 까지 수행하는 것을 말한다.
array[n]에는 재귀 호출을 할때와 동일한 값이 계산되어 저장된다.

8. DP 구현
bottom up 방식의 Dynamic Programming은 0부터 커져나가는 for문으로 구현할 수 있다.
```cpp
for(int i = 2 ; i <= n ; i++)
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-2]) % 10007;
```
=> 밑에서 부터 추후에 사용할 값을 채워 나가는 것이다.

5. 최종 구현
```cpp
#include <iostream>

using namespace std;

int dp[1001];

int main(){
    int n;
    cin>>n;
    dp[0] = 1;
    dp[1] = 1; //0과 1을 1로 초기화
    
    for(int i = 2 ; i <= n ; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-2]) % 10007;
    
    cout<<dp[n]<<endl;
}
```
#### 느낀점 및 성과
1. 가물 가물 했던 DP 문제의 접근법을 정확하게 알 수 있었다.
2. 함수의 배열화를 알고 나니 Dynamic Programming 의 기본 컨셉을 알 수 있었다.
3. 함수 호출 대신 배열에 값을 저장한다는 컨셉을 여러 문제를 통해 익혀야 겠다.

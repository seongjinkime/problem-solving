![Problem](https://github.com/seongjinkime/problem-solving/raw/master/images/9095.png)
[문제 바로가기](https://www.acmicpc.net/problem/9095)
### Type : Dynamic Programming

#### 접근
1.  0부터 시작하여 1,2,3을 각각 더해 n까지 도달할 수 있는 경우를 재귀탐색 한다
```
f(0) -> f(0+1) + f(0+2) + f(0+3)
f(1) -> f(1+1) + f(1+2) + f(1+3)
f(2) -> f(2+1) + f(2+2) + f(2+3)
...
```

2. 만약 n이라는 숫자가 정확하게 만들어 졌다면 true
   그렇지 않다면 false를 반환 한다.

3. 일반 재귀 함수
```cpp
int find(int num){
  if(num == n){
    return true;
  }
  if(num > n){
    return false;
  }

  return find(num+1) + find(num+2) + find(num+3);
}
```

**문제에선 최대 값이 11이므로 메모이제이션을 활용하지 않아도 통과 한다**
**하지만 30이상이 넘어 가는 경우는 시간초과가 발생 한다**



#### 주요 포인트  
1. 메모이제이션
- 중복되는 탐색을 없앤다
```
    0
    1 2 3
    1
    2 3 4
    3
    4 5 6
```
2. 함수의 배열화를 통한 메모이제이션
* 1~3 까지 더하는 동안 n을 초과하지 않는 범위 내에서
  * 배열에 값이 이미 들어 있다면 저장된 값을 사용 하고
  * 그렇지 않다면 탐색 후 배열에 값을 저장 한다.
  * 겅우의 수에 탐색 결과 혹은 배열의 값을 더한다.

```cpp
for(int i = 1 ; i <= 3 ; i++){
    if(num + i > n)
        continue;
    if(memo[num+i] == 0){
        memo[num+i] = find(num+i);
    }
    ret += memo[num+i];
}
```


#### 구현 코드

```cpp
#include <iostream>
#include <algorithm>
#define LL long long
#define MAX 100
using namespace std;

int n;
LL memo[MAX];

LL find(int num){
    LL ret = 0;
    //n이 만들어 졌으므로 true 반환
    if(num == n)
        return true;
    //n을 초과했으므로 false 반환
    if(num > n)
        return false;

    for(int i = 1 ; i <= 3 ; i++){
        if(num + i > n)
            continue;
        if(memo[num+i] == 0){
            memo[num+i] = find(num+i);
        }
        ret += memo[num+i];
    }

    return ret;

}
int main(void){
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        cin>>n;
        fill_n(memo, MAX, 0);
        cout<<find(0)<<endl;
    }
}


```

### 깨달은 점
1. 메모이제이션을 활용한 탐색의 수 줄이기
2. 재귀 호출을 통해 n을 만들 수 있는 수의 조합을 찾아나갈 수 있다

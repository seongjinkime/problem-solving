![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1644.png)
[문제 바로가기](https://www.acmicpc.net/problem/1644)
### Type : 브루트포스

#### 접근
1. n 이하의 모든 소수를 저장한 배열을 만든다.
  **소수 배열을 만들때는 [에라토스테네스의 체](https://ko.wikipedia.org/wiki/에라토스테네스의_체)를 활용 한다**  

2. 에라토스테네스의 체
  - 2부터 n 까지의 소수를 구하는 방법 이다.  
  - x의 배수는 x를 약수로 가진다는 원리를 이용 한다.
  * 2부터 n까지 순회 하며
    * 만약 숫자가 소수 라면
      * (숫자 + 숫자) ~ n 까지 순회
        * 소수[숫자]는 false
        * 숫자 = 숫자 + 숫자


3. [부분 합](https://www.acmicpc.net/problem/1806) 문제와 동일하게 투포인터 알고리즘을 활용하여
  소수 만으로 n을 만들 수 있는 경우의 수를 구한다

#### 주의할 점
(1)인덱스 초과 에러를 방지 하기 위해 탐색 범위를 n 이 아닌 vector의 size로 지정 해야 한다
(2)n이 1로 주어질때는 만들 수 있는 소수가 없기 때문에 소수 배열에 접근하려고 할때 인덱스 에러 발생 함
  * 1일때만 0을 바로 출력후 종료

#### 플로우 차트
(1) 소수 배열 생성을 위한 build
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1644_build.png)
(2) 가능한 수 카운트를 위한 solve
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1644_solve.png)

#### 구현 코드

```cpp
#include <iostream>
#include <vector>
#define limit 4000001

using namespace std;

vector<int> primes;
int n;

void solve(){
    int i, j, sum, cnt;
    i = j = cnt = 0;
    sum = primes[i];
    int size = primes.size();

    while(i < size && j < size){
        if(sum < n){
            sum += primes[++i];
        }else if(sum == n){
            cnt++;
            sum += primes[++i];

        }else if(sum > n){
            sum -= primes[j++];
            if(j > i){
                sum = primes[j];
                i = j;
            }
        }
    }
    cout<<cnt<<endl;
}

void build(){
    bool prime[n+1];
    fill_n(prime, n+1, true);

    for(int i = 2 ; i <= n ; i++){
        if(!prime[i])
            continue;
        for(int j = i+i ; j <= n ; j+=i)
            prime[j] = false;
    }

    for(int i = 2 ; i <= n ; i++){
        if(prime[i]){
            primes.push_back(i);
        }
    }
}


int main(int argc, const char * argv[]) {
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    build();
    solve();
    return 0;
}



```

### 깨달은 점
1. 1은 소수가 아니다. 소수는 2부터 시작된다.
2. 순회 범위를 잘 생각하여 지정해주어야 한다.

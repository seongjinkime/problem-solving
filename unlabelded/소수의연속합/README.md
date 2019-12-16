![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1644.png)
[문제 바로가기](https://www.acmicpc.net/problem/1644)
### Type : 브루트포스

#### 접근
1. 4백만 이하의 모든 소수를 저장한 배열을 만든다.
  **소수 배열을 만들때는 [에라토스테네스의 체](https://ko.wikipedia.org/wiki/에라토스테네스의_체)를 활용 한다**  

2. 에라토스테네스의 체
  - 2부터 n 까지의 소수를 구하는 방법 이다.  
  - x의 배수는 x를 약수로 가진다는 원리를 이용 한다.
  * 2부터 n까지 순회 하며
    * 만약 숫자가 소수 라면
      * (숫자 * 숫자) ~ n 까지 순회
        * 소수[숫자]는 false
        * 숫자 = 숫자 + 숫자


3. [부분 합](https://www.acmicpc.net/problem/1806) 문제와 동일하게 투포인터 알고리즘을 활용하여
  소수 만으로 n을 만들 수 있는 경우의 수를 구한다
  **중요 : 인덱스 초과 에러를 방지 하기 위해 탐색 범위를 n 이 아닌 vector의 size로 지정 해야 한다**


#### 구현 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4000001

using namespace std;
bool isPrime[MAX];
vector<int> primes;
int n;


void solve(){
    //투 포인터 알도리즘 구현
    int low, high;
    int sum;
    int cnt = 0;
    low = high = 0;
    sum = primes[0];
    //중요 : high의 범위를 n이 아닌 소수 배열의 사이즈로 지정한다
    while(low <= high && high<primes.size()){
        if(sum<n){
            high++;
            sum += primes[high];
        }else if(sum==n){
            cnt++;
            high++;
            sum += primes[high];
        }else if(sum>n){
            sum -= primes[low];
            low++;
            if(low > high && low<primes.size()){
                high = low;
                sum = primes[low];
            }
        }
    }
    cout<<cnt<<endl;

}

void build(){
    //에라토스테네스의 체 구현
    //1. 모든 수를 소수로 초기화
    for(int i = 1 ; i <= n ; i++)
        isPrime[i] = true;
    //배열 초과 접근을 방지하기 위해 순회 범위를 i*i <= n으로 지정한다
    for(int i = 2; i * i <= n ; i++){
        if(isPrime[i]){
            for(int j = i*i ; j<=n ; j+=i){
                isPrime[j] = false;
            }
        }
    }
    //소수 vector 생성
    for(int i = 2 ; i <= n ; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}


int main(int argc, const char * argv[]) {
    //입력
    cin>>n;
    //만약 n이 1이라면 0 출력
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    //소수 배열 생성
    build();
    //문제 풀이 진행
    solve();
    return 0;
}


```

### 깨달은 점
1. 1은 소수가 아니다. 소수는 2부터 시작된다.
2. 순회 범위를 잘 생각하여 지정해주어야 한다.

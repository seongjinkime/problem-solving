![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2003.png)
[문제 바로가기](https://www.acmicpc.net/problem/2003)
### Type : 브루트 포스, 투 포인터

#### 접근
(1) 연속된 수의 합을 찾기 위한 O(n) 알고리즘으로 투 포인터 알고리즘 이 있다  
(2) 투 포인터 알고리즘 이란 피봇 2개를 적절히 움직여 답이 되는 구간 혹은 경우의 수를 찾는 알고리즘을 말한다.

#### 플로우차트
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2003_solve.png)

#### 주의할 점
(1) i보다 j가 더 커지는 경우가 존재 한다.
```
ex) n = 8, arr = 1, 2, 9, 2
```
i가 9 위에 존재 할 때 항상 sum이 n 보다 크므로 j를 계속 증가 시킨다  
이를 대비하여 j가 i를 넘어 갈때는 sum 과 i 를 다시 초기화 시켜 준다.

#### 구현 코드



```cpp

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n, m;

int solve(){
    int cnt = 0;
    int sum = arr[0];
    int i, j;
    i = j = 0;

    while (i < n && j < n ) {
        if(sum < m){
            sum += arr[++i];
        }else if(sum == m){
            cnt++;
            sum += arr[++i];
        }else if(sum > m){
            sum -= arr[j++];
            if(i < j){
                sum = arr[j];
                i = j;
            }
        }
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    arr = vector<int>(n);
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }
    cout<<solve()<<endl;
    return 0;
}


```

### 깨달은 점
1. 배열의 연속합을 구할때 투 포인터 알고리즘을 사용할 수 있다.

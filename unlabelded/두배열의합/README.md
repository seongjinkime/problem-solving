![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2143.png)
[문제 바로가기](https://www.acmicpc.net/problem/2143)
### Type : 투포인터, 브루트포스

#### 접근
(1) 하나의 배열 마다 가능한 모든 부분 배열을 생성 한다.
(2) 두개의 부분배열에서 합이 t 가 되는 경우의 수를 찾는다.

#### 플로우 차트
(1) 가능한 모든 부분 배열을 생성하기 위한 알고리즘
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2143_build.png)
(2) t 가 되는 경우의 수를 세기 위한 알고리즘
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2143_solve.png)

#### 구현 코드



```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
vector<int> subsA, subsB;

void solve(){
    long long cnt = 0;
    sort(subsA.begin(), subsA.end());
    sort(subsB.begin(), subsB.end());

    for(int i = 0 ; i < subsA.size() ; i++){
        int diff = t - subsA[i];
        auto ub = upper_bound(subsB.begin(), subsB.end(), diff);
        auto lb = lower_bound(subsB.begin(), subsB.end(), diff);
        cnt += (ub-lb);
    }
    cout<<cnt<<endl;
}

void build(){
    int n, m;
    int sum;
    vector<int> numsA, numsB;
    cin>>n;
    numsA = vector<int>(n);

    for(int i = 0; i < n ; i++)
        cin>>numsA[i];

    cin>>m;
    numsB = vector<int>(m);
    for(int i = 0 ; i < m ; i++)
        cin>>numsB[i];



    for(int i = 0 ; i < n ; i++){
        sum = 0;
        for(int j = i ; j < n ; j++){
            sum += numsA[j];
            subsA.push_back(sum);
        }
    }

    for(int i = 0 ; i < m ; i++){
        sum = 0;
        for(int j = i ; j < m ; j++){
            sum += numsB[j];
            subsB.push_back(sum);
        }
    }

}

int main(int argc, const char * argv[]) {
    cin>>t;
    build();
    solve();
    return 0;
}

```

### 깨달은 점
1. 투 포인터 알고리즘을 통해 가능한 모든 부분 배열을 구할 수 있음
2. upper_bound, lower_bound의 차이를 통해 배열에 속한 x 의 갯수를 구할 수 있음

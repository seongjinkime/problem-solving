![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1248.png)
[문제 바로가기](https://www.acmicpc.net/problem/1248)
### Type : 브루트 포스 + 백트랙킹

#### 접근
1. 행렬 생성
  * 규현이는 비행기에서 구간합을 2차원 행렬로 표현하였다  
  * 각 행과 열에는 구간합의 기호를 표시 하였다 (+, 0, -)
  * ex) -2, 5, -3, 1

      |i\j|1|2|3|4|
      |------|---|---|---|---|
      |1|-|+|0|+|
      |2| |+|+|+|
      |3| | |-|-|
      |4| | | |+|

2. 퇴각 검사  
  * 순열의 n 번째 숫자를 지정할 때, n 번째 숫자가 모든 구간합의 기호를 만족하는지 검사 한다  
  * 즉 위의 도표에서 j 번째 숫자가 들어 왔을 때 모든 i ~ j 구간합 기호가 일치 하는지 검사 한다.
  * ex) j = 4 : check(4, 4), check(3, 4), check(2, 4), check(1, 4)

3. 브루트 포스
  * 퇴각 검사를 모두 통과하여 n 번째의 순열을 만들 수 있을때 모든 순열의 숫자를 출력한 후 return 한다.  

#### 플로우 차트  
1. 모든 구간 합의 기호를 검사하는 퇴각 검사 qualified  
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1248_qualified.png)

2. 조건을 만족하는 순열을 탐색하는 find 함수
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1248_find.png)

#### 구현 코드



```cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<int>nums;
vector<int>perm;
string input;
vector<vector<char>> table;

bool qualified(int j){
    int sum = 0;
    for(int i = idx ; i >= 0 ; i--){
        sum += perm[i];
        if(table[i][j] == '+' && sum <= 0)
            return false;
        else if(table[i][j] == '-' && sum>=0)
            return false;
        else if(table[i][j] == '0' && sum !=0)
            return false;
    }
    return true;
}

void find(int cnt){
    if(cnt == n){
        for(int i = 0 ; i < n ; i++){
            cout<<perm[i]<<" ";
        }
        exit(0);
    }

    for(int i = 0 ; i < 21 ; i++){
        perm.push_back(nums[i]);
        if(qualified(cnt)){
            find(cnt+1);
        }
        perm.pop_back();

    }
}

void build(){
    cin>>input;
    int idx = 0;
    table = vector<vector<char>>(n, vector<char>(n));
    //string 입력후 기호 행렬 생성
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            table[i][j] = input[idx++];
        }
    }
    for(int i = -10; i<=10 ; i++){
        nums.push_back(i);
    }

}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    build();
    find(0);
    return 0;
}


```

### 깨달은 점
1. 구간합을 2차원 행렬로 표현할 수 있다
2. i - j 구간을 j 가 아닌 i를 변경하면서 검사 할 수 있다  

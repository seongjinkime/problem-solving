![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1107.png)
[문제 바로가기](https://www.acmicpc.net/problem/1107)
### Type : 브루트포스

#### 접근
1. 범위 설정
  * 수빈이가 이동하려는 채널의 최대값은 500000 이다.
  * 이동할 수 있는 채널은 무한대이다.
  * MAX ch 보다 작은 곳에서 이동하는 경우, MAX ch 보다 큰곳에서 이동하는 경우를 모두 고려해야 한다.
  * 따라서 탐색범위를 0 ~ 1000000 으로 설정해야 한다.

2. 최소값을 찾는 방법  
  * 최소값을 찾기위해선 버튼을 누르는 순서가 중요하다
  * +,- 버튼을 누른 뒤 숫자버튼을 누르면 +,- 가 상쇄된다
  * (+ + - - ++) 의 경우엔 중복된 탐색이 발생한다.
  * **반드시 숫자 버튼을 누른 뒤 +, - 를 눌러야 한다**
  * **+, - 중 하나의 버튼만을 연속해서 눌러야 한다**


3. 버튼 누르는 방법
  * 숫자 버튼을 누르기 위해선 0~100000 만까지의 숫자를 발생 시켜 본다
    * 발생된 숫자가 리모콘으로 누를 수 있는 숫자인지 확인 한다.  
  * +,- 를 누르기 위해서 |current-target| 으로 두 채널의 차이를 구한다

4. 초기값 설정
  * 수빈이의 현재 채널은 100 이다.
  * 숫자 버튼을 누르지 않고 +, - 만으로도 더 빨리 이동할 수 있는 경우가 존재한다.
  * ex) 99
  * 따라서 초기값은 |N-100| 으로 설정해준다

#### 플로우 차트  
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1107_solve.png)

![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1107_possible.png)

#### 구현 코드



```cpp
#include <iostream>
#include <math.h>
#include <set>

using namespace std;
set<int> broken;
int ret;

bool possible(int num, int& len){

    if(num == 0){
        if(broken.count(0) == 0){
            len = 1;
            return true;
        }else{
            return false;
        }
    }

    while(num > 0){
        int digit = num % 10;
        if(broken.count(digit) > 0)
            return false;
        len++;
        num /= 10;
    }

    return true;
}


void solve(int n){
    int len, cnt;
    ret = abs(n-100);
    for(int i = 0 ; i<=1000000 ; i++){
        len = 0;
        if(!possible(i, len)){
            continue;
        }
        cnt = abs(n-i);
        ret = min(ret, len+cnt);
    }
    cout<<ret<<endl;
}

int build(){
    int n, cnt, num;
    cin>>n>>cnt;
    for(int i = 0 ; i < cnt ; i++){
        cin>>num;
        broken.insert(num);
    }
    return n;
}


int main(int argc, const char * argv[]) {
    int n;
    n = build();
    solve(n);
    return 0;
}

```

### 깨달은 점
1. 문제의 정답이 될 수 있는 범위가 문제로 주어진 수 보다 넓다면 양쪽에서 도달 할 수 있는 경우를 생각해본다.
2. 초기값을 설정하여 더 빨리 도달 할 수 있는 경우를 생각해본다.

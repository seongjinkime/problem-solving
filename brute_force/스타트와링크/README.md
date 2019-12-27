![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/14889.png)
[문제 바로가기](https://www.acmicpc.net/problem/14889)
### Type : 브로트포스

#### 접근
1. 조합 생성  
  * 0 ~ n 까지 나올 수 있는 2/n 길이의 조합을 생성한다.
  * **a, b, c 와 b a c 혹은 동일한 선수가 들어간 모든 팀의 능력치는 동일하다**
  * **매번 다른 수의 조합을 생성하여 비교 해야 한다**

2. 능력치 비교
  * 조합으로 선택된 선수는 a팀, 그렇지 않은 선수는 b팀으로 나눈다.
  * 모든 선수 쌍의 능력치를 팀별로 구한 후 두 팀의 차이를 구한다.

#### 플로우 차트
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/14889_select.png)
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/14889_between.png)


#### 구현 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<bool> selected;
int n, ret;

int between(){
    vector<int> a, b;
    for(int i = 0 ; i < n ; i++){
        if(selected[i])
            a.push_back(i);
        else
            b.push_back(i);
    }
    int sumA, sumB;
    sumA = sumB = 0;

    for(int i = 0 ; i < n/2 ; i++){
        for(int j = 0 ; j < n/2 ; j++){
            if(i==j)
                continue;
            sumA += board[a[i]][a[j]];
            sumB += board[b[i]][b[j]];

        }
    }

    return abs(sumB-sumA);
}


void select(int here, int cnt){
    if(cnt == n/2){
        ret = min(ret, between());
        return;
    }

    for(int there = here ; there< n ; there++){
        if(!selected[there]){
            selected[there] = true;
            select(there, cnt+1);
            selected[there] = false;
        }
    }
}

void build(){
    ret = 987654321;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    selected = vector<bool>(n, false);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>board[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    vector<bool> selected (n, false);
    build();
    select(0,0);
    cout<<ret<<endl;

    return 0;
}


```

### 깨달은 점
1. 나머지에 수를 더함으로써 몫을 계산 할 수 있다 (오버 플로우 방지)
2. 알고리즘 문제에 long long으로 연산이 불가능한 경우가 출제 된다.
3. 탐색 목적을 명확히 해야 한다.  
  - 이번 문제는 나머지가 0이 될때까지의 최소 수를 탐색
  - 한번 방문한 나머지는 다시 방문하지 않아도 됨

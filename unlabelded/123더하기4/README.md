![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/15989.png)
[문제 바로가기](https://www.acmicpc.net/problem/15989)
### Type : Dynamic Programming

#### 접근
1. **중복된 원소를 걸러내는 방법을 아는 것이 주요 포인트**  
  **중복을 방지하기 위헤 조건을 걸어야 한다**
  **이 문제에선 맨 처음 숫자보다 작거나 큰수의 경우만 경우의 수로 합산한다**  
  예를 들어 1 + 3 과 3 + 1 이 있을때 1 + 3 은 추가될 수 없다

2. 재귀 함수로 생각 해보기

```cpp
  int find(int num, vector<int> arr){
      if(num == n){
        if(arr.size() > 1 && arr[1] > arr[0]){
          return false;
        }
        return true;
      }
      if(num > n){
        return false;
      }
      ...

  }
```

- 대략적인 재귀 함수의 탈출 조건을 생각하면 위와 같이 구성 할 수 있다.
- 하지만 재귀 함수를 통해 구현하면 시간 초과가 발생할 것이다 (메모이제이션 활용 불가)
- 따라서 함수를 배열화 한 Dynamic Programming을 통해 문제에 접근한다.  

3. 함수의 배열화  
- [1,2,3 더하기 3]("https://www.acmicpc.net/problem/15988") 문제 처럼
  * 1 부터 시작하는 경우
  * 2 부터 시작하는 경우
  * 3 부터 시작하는 경우  
  를 생각해본다  
  </br>
  </br>
- 중복을 방지하기 위한 조건을 구해본다  
  * 만약 1 부터 시작 한다면 뒤에 올 수 있는 숫자는 1 밖에 없다
  * 만약 2 부터 시작 한다면 뒤에 올 수 있는 숫자는 1 혹은 2 이다
  * 만약 3 부터 시작 한다면 뒤에 올 수 있는 숫자는 1 혹은 2 혹은 3 이다




4. 출력 함수  
BFS 트리의 루트로 깊이 우선 탐색을 한다  
루트에 다다르면 재귀 호출을 종료하면서 라벨링된 수를 출력한다  

#### 구현 코드



```cpp

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <map>
#define FAIL "BARK"
#define MAX 20001

using namespace std;
//자료 구조 선언
map<int, char> numByRemain;
bool visited[MAX];
int parents[MAX];
int n;

//탐색 진행
void bfs(){
    queue<int> q;
    q.push(1);
    parents[1] = -1;
    visited[1] = true;
    numByRemain[1] = '1';
    while(!q.empty()){
        int current = q.front();
        q.pop();
        int newNums[2];
        //후보 생성
        newNums[0] = (current*10) % n;
        newNums[1] = (current*10+1) % n;
        for(int i = 0 ; i < 2 ; i++){
            int newNum = newNums[i];
            if(visited[newNum])
                continue;
            //나머지를 위해 덧붙인 수 라벨링
            numByRemain[newNum] = i + '0';
            //부모 정보 저장
            parents[newNum] = current;

            if(newNum==0)
                return;


            visited[newNum] = true;
            q.push(newNum);
        }

    }
}
//출력을 위한 깊이우선 탐색
void print(int num){
    if(num == -1){
        return;
    }
    print(parents[num]);
    cout<<numByRemain[num];
}


int main(void){
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        cin>>n;
        memset(visited, false, sizeof(visited));
        bfs();
        print(0);
        cout<<endl;
    }

    return 0;
}

```

### 깨달은 점
1. 나머지에 수를 더함으로써 몫을 계산 할 수 있다 (오버 플로우 방지)
2. 알고리즘 문제에 long long으로 연산이 불가능한 경우가 출제 된다.
3. 탐색 목적을 명확히 해야 한다.  
  - 이번 문제는 나머지가 0이 될때까지의 최소 수를 탐색
  - 한번 방문한 나머지는 다시 방문하지 않아도 됨

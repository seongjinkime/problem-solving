![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/8111.png)
[문제 바로가기](https://www.acmicpc.net/problem/8111)
### Type : BFS

#### 접근
1. 핵심 원리   
  **나머지에 0과 1을 덧붙이면 몫에도 동일한 수가 덧붙여 진다**  
  **나머지에 0과 1을 덧붙인 후 다시 n을 나누면 몫에 0과 1을 덧붙여 나눈것과 동일한 결과**  
  예를 들어 10 % 7 = 3 일때  
  나머지가 30 이면 몫이 100  
  나머지가 31 이면 몫이 101  

  **BFS 탐색을 통해 몫에 0 혹은 1을 덧붙여 나가면 오버플로우가 발생 한다**  
  **나머지가 0이 될때까지 나머지에 0혹은 1을 덧붙여 나가는 탐색을 진행 한다**  
  **BFS 트리의 루트까지 찾아가 역순으로 어떤 수를 덧붙였는지 출력한다**

2. 자료 구조  
  map <int, char> numByRemain : 나머지를 만들기 위해 어떤 수를 덧붙였는지 저장 (라벨링)  
  int parents[] : BFS 트리의 부모 정보를 담기 위한 배열  
  bool visited[] : 이미 한번이상 방문한 나머지 인지 저장하기 위한 배열  

3. 탐색 진행
* 탐색이 끝날때 까지
  * 큐로부터 현재 나머지를 꺼낸다
  * 후보 1 : (현재 나머지 * 10) % n
  * 후보 2 : (현재 나머지 * 10 + 1) % n
    * 만약 후보가 한번도 계산 되지 않은 나머지 라면
      * 나머지를 만들기 위해 덧붙인 수 라벨링
      * 부모[후보] = 현재 나머지
      * 만약 후보가 n으로 나누어 떨어 진다면
          * 탐색 종료
      * 방문 표시
      * q에 후보 추가

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

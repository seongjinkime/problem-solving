![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/13913.png)
[문제 바로가기](https://www.acmicpc.net/problem/13913)
### Type : BFS

#### 접근
(1) 수빈이가 동생을 찾기 위한 가장 빠른 경로를 찾기 위해 BFS 탐색을 실시한다.
(2) 한 지점을 방문할때 마다 부모 정보를 저장 한다.
(3) 부모의 배열을 뒤집어 출력 한다.

#### 자로 구조
(1) arr[MAX] : 탐색을 위한 1차원 배열
(2) parent[MAX] : 부모 정보를 저장할 1차원 배열
(3) map<int, int> :  탐색 거리를 저장할 map

#### 플로우 차트
(1) BFS 탐색
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/13913_bfs.png)
(2) 경로 출력
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/13913_printpath.png)

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

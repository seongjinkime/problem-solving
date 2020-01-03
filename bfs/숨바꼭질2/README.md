![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/12851.png)
[문제 바로가기](https://www.acmicpc.net/problem/12851)
### Type : BFS

#### 접근
(1) 경로의 수를 담기 위한 배열을 사용 한다.  
(2) 한 노드 까지 도달 할 수 있는 경로의 수는 직전 노드까지 도달 할 수 있는 경로수들의 합 이다.  
(3) 만약 방문 하지 않은 노드 라면 미방문 노드의 경로수를 현재 노드 까지의 경로수로 갱신한다.
(4) 만약 방문한 노드 라면 현재 노드 까지의 경로수를 더해 준다.

#### 플로우 차트
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/12851_bfs.png)

#### 구현 코드



```cpp
#include <iostream>
#include <map>
#include <queue>
#define MAX 100001

using namespace std;

int arr[MAX];
int paths[MAX];
map<int, int> dist;

int n, k;
bool inRange(int x){
    return 0<=x && x< MAX;
}

bool visited(int x){
    return dist.count(x) > 0;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    paths[start] = 1;

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int npos : {here+1, here-1, here*2}){
            if(!inRange(npos))
                continue;
            if(!visited(npos)){
                dist[npos] = dist[here]+1;
                paths[npos] = paths[here];
                q.push(npos);
            }else if(dist[npos] == dist[here]+1){
                paths[npos] += paths[here];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    bfs(n);
    cout<<dist[k]<<endl;
    cout<<paths[k]<<endl;

    return 0;
}


```

### 깨달은 점
1. 경로의 수를 저장할 배열을 만들어 사용할 수 있다.
2. 탈출 조건은 가능한 모든 지점을 방문했을 때이다.

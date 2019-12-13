![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/15558.png)
[문제 바로가기](https://www.acmicpc.net/problem/15558)
### Type : BFS

#### 접근
1. 문제에 주어진 조건을 잘 지키면서 일반적인 BFS와 유사한 탐색을 진행 한다.  
조건 1. 시간이 지날때마다 한칸이 사라지므로 시도횟수가 n을 넘어서면 안된다.  
조건 2. x>=n 이다. 배열의 시작은 0부터 시작되므로 n과 동일하기만 해도 범위를 벗어난 것이다.  
조건 3. 시간이 지나 사라지거나 0이 표시된 위치로는 접근 할 수 없다.
조건 4. 이미 방문한 곳은 다시 방문 할 수 없다.  

2. 구조체 선언
   위치 (y, x)와 시간(time)을 저장할 수 있는 구조체를 선언한다.

3. 탐색 진행 
 * 탐색이 끝나거나 게임에 성공할때까지. 
    * 큐로부터 walker 객체를 꺼낸다
    * 문제에 주어진 동작에 따라 3가지의 새로운 walker 객체를 만든다.
        * 만약 새 walker의 x가 n보다 크거나 같다면
            * 성공 확정
        * 새 walker를 이동시킬수 있고 아직 방문하지 않은 곳이라면. 
            * 방문 표시
            * 새 walker의 time 1증가
            * 큐에 새 walker 추가
* 성공여부 출력

4. 새 walker 생성
walker 1. x+1 칸 이동
walker 2. x-1 칸 이동
walker 3. y+1 or y-1, x+k 이동

5. 이동 가능 여부 판단
조건 1. 0 < y <1
조건 2. time < x < n
** 시간이 지나 없어진 곳은 이동 할 수 없으므로 0이 아닌 time과 비교해준다.  


#### 구현 코드



```cpp
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000+1

using namespace std;
struct walker{ int y, x, time;};
//udrl
int dy[4] {0, 0, -1, 1};
int dx[4] {-1, 1, 0, 0};
int map[2][MAX];
bool visited[2][MAX];
int n,k;

//접근 5. 이동 가능 여부 판단
bool inRange(walker w){
    return 0<=w.y && w.y< 2 && w.time < w.x && w.x<n; //!
}
//접근 4. 새 walker 생성
vector<walker> newWalkers(walker w){
    vector<walker> walkers;
    walkers.push_back({w.y, w.x+1, w.time});
    walkers.push_back({w.y, w.x-1, w.time});
    walkers.push_back({(w.y+1)%2, w.x+k, w.time});
    return walkers;
}

//접근 3. 탐색 진행
void solve(){
    queue<walker> q;
    q.push({0,0,0});
    visited[0][0] = true;
    bool succed = false;
    
    while(!q.empty() && !succed){
        walker current = q.front();
        q.pop();
        if(current.time >= n){ //!
            break;
        }
        for(walker nw : newWalkers(current)){
            if(nw.x >= n) //!
                succed = true;
            
            if(inRange(nw) && !visited[nw.y][nw.x]){
                if(map[nw.y][nw.x] == 1){
                    nw.time+=1;
                    visited[nw.y][nw.x] = true;
                    q.push(nw);
                }
                
    
            }
        }
    }
    cout<<succed<<endl;
}

void build(){
    for(int y = 0 ; y < 2 ; y++){
        for(int x = 0 ; x< n ; x++){
            scanf("%1d", &map[y][x]);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin>>n>>k;
    build();
    solve();
 
    //cout<<0<<endl;
    return 0;
}


```
### 실수한 점
1. dfs와 bfs를 혼동하여 일반적인 탐색 풀이를 생각하지 못했다.  
2. Visit 배열을 처음부터 사용하지 않았다.  
3. 문제의 탐색 조건을 잘 해석하지 못하여 지속된 실수를 만들어 냈다.

### 깨달은 점
1. 이동하며 탐색하는 BFS는 반드시 방문 배열을 사용해야 한다. 
2. 문제의 조건을 잘 파악하여 풀어야 한다. 
	- 0부터 시작하므로 n과 같으면 배열을 초과 한 것 등

![Problem](https://github.com/seongjinkime/problem-solving/raw/master/images/4991_1.png)
![Problem](https://github.com/seongjinkime/problem-solving/raw/master/images/4991_2.png)
### Type : BFS + DFS

#### 접근
1.  BFS를 통해 로봇, 각 쓰레기 간의 거리를 구한다.
(1) 로봇 -> 쓰레기 1, 쓰레기 2, 쓰레기 3  
(2) 쓰레기 1 -> 로봇, 쓰레기 2, 쓰레기 3  
(3) 쓰레기 2 -> 로봇, 쓰레기 1, 쓰레기 3   
(4) 쓰레기 3 -> 로봇, 쓰레기 1, 쓰레기 2   
<br>

2. 각 지점간의 거리를 MST Table로 생성한다.  

    |        | R | T1  | T2  | T3  |   
    |:---:   |:---:  |:---:|:---:|:---:|
    | R      | 0 |  |   |   |
    |  T1    |   | 0 |   |   |
    |  T2    |   |   | 0 |   |
    |  T3    |   |   |   | 0 |

<br>

3. Robot에서 출발하여 어떤 순서로 가야 최소한의 거리로 모든 쓰레기를 치울 수 있는지 구한다  
  - DFS 순열 생성을 통해 각기 다른 순서를 만들어 낸다
  - MST Table의 거리를 순서에 따라 합산한다.  
  - 합산한 것들 중 최소한의 값을 구한다.  



#### 주요 포인트  
  - **무조건 가까운 지점만 찾는다고 최적의 거라기 구해지진 않는다**
  ex)  * R * * : 왼쪽~오른쪽으로 탐색 해야 함
  - **각 구간의 거리를 2차원 배열로 저장할 수 있다**
    (1) bfs를 통해 시작점을 기준으로 각 종착지간의 거리가 담긴 Path 배열을 받는다
    (2) dist[i][j] = path[y][x] 를 통해 MST 배열을 생성한다
  - **순열 조합을 통해 각기 다른 탐색 순서를 만들 수 있다**
  - *주의: 반드시 Robot부터 시작해야 하므로 순열 생성 구간은 1부터 시작 한다*

#### 구현 코드

```cpp

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <queue>
#define INF 987654321
#define MAX 21
#define CLEAN '.'
#define DIRTY '*'
#define FURNITURE 'x'
#define ROBOT 'o'

using namespace std;
typedef vector<vector<int>> table;
typedef pair<int, int> pos;

vector<pos>tasks;
bool selected[11];
table dist;
int dy[4] {-1, 1, 0, 0};
int dx[4] {0, 0, -1, 1};
int ret;
char map [MAX][MAX];

int w, h;

bool inRange(int y, int x){
    return 0<=y && y < h && 0<=x && x<w;
}

//start를 기준으로 한 거리를 반환하기 위한 BFS 함수
table bfs(int y, int x){
    int sy, sx, ny, nx;
    table visited = table(h, vector<int>(w, -1));
    queue<pos> q;
    q.push(pos(y, x));
    visited[y][x] = 0;
    while (!q.empty()) {
        pos here = q.front();
        sy = here.first;
        sx = here.second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            ny = sy + dy[i];
            nx = sx + dx[i];
            if(!inRange(ny, nx))
                continue;
            if(visited[ny][nx]!=-1)
                continue;
            if(map[ny][nx] == FURNITURE)
                continue;

            visited[ny][nx] = visited[sy][sx] + 1;
            q.push(pos(ny, nx));
        }
    }
    return visited;
}

//청소 순서를 위한 순열 생성 함수
void dfs(int here, int cnt, int sum){
    if(cnt == tasks.size()-1){
        //cout<<cnt<<" "<<sum<<endl;
        ret = min(ret, sum);
        return;
    }
    //주의 : 로봇부터 시작해야 하므로 1부터 시작
    for(int there = 1 ; there < tasks.size() ; there++){
        if(!selected[there]){
            selected[there] = true;
            //주의 : 기존 값을 변경하지 않기위해 새로운 변수 사용
            int next = sum + dist[here][there];
            dfs(there, cnt+1, next);
            selected[there] = false;
        }
    }
}

void build(){
    char ch;
    tasks.clear();
    memset(selected, false, sizeof(selected));
    //robot일경우 배열의 맨 앞에 위치 추가
    //쓰레기일 경우 배열의 맨 뒤에 위치 추가
    for(int y = 0 ; y < h ; y++){
        for(int x = 0; x < w ; x++){
            cin>>ch;
            if(ch == ROBOT){
                tasks.insert(tasks.begin(), pos(y, x));
            }else if (ch == DIRTY){
                tasks.push_back(pos(y, x));
            }
            map[y][x] = ch;

        }
    }

}

void solve(){
    build();
    ret = INF;
    int sy, sx, dy, dx;
    table path;
    //MST를 위한 배열 선언
    dist = table(tasks.size(), vector<int>(tasks.size(), 0));
    //task 순화
    for(int i = 0 ; i < tasks.size() ; i++){
        sy = tasks[i].first;
        sx = tasks[i].second;
        //각기 다른 시작점을 기준으로 한 거리 받음
        path = bfs(sy, sx);
        for(int j = 0 ; j < tasks.size() ; j++){
            dy = tasks[j].first;
            dx = tasks[j].second;
            //MST 배열에 값 할당
            //i = 출발지, j = 도착지
            dist[i][j] = path[dy][dx];
            if(dist[i][j] == -1){
                cout<<-1<<endl;
                return;
            }
        }
    }
    //순열 생성 및 최소값 갱신
    dfs(0, 0, 0);
    //정답 출력
    cout<<ret<<endl;
}


int main(int argc, const char * argv[]) {
    while(true){
        cin>>w>>h;
        if(w==0 && h ==0){
            break;
        }
        solve();
    }
    return 0;
}

```

### 깨달은 점
1. 반드시 가장 가까운 위치를 찾아간다고 해서 최적의 값을 보장해주지는 않는다

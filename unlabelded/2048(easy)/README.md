![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/12100.png)
[문제 바로가기](https://www.acmicpc.net/problem/12100)
### Type : BFS, 브루트 포스

#### 접근
(1) 맨 초기 상태에서 상, 하, 좌, 우 로 테이블을 기울여나간다 (BFS 탐색 사용)
(2) 기울인 상태마다 가장 큰 블록의 수를 찾는다
(3) 맨 초기부터 5회 이상 기울였다면 BFS 탐색을 중지 한다.

#### 자료 구조
(1) typedef vector<vector<int>> table : 블록의 상태를 저장할 2 차원 정수 배열 자료형
(2) typedef vector<vector<bool>> crashed : 충돌 여부를 저장할 2차원 불리언 배열 자료형
(3) map<table, int> dist : 맨 초기 상태로 부터의 거리를 저장할 map 자료 구조

#### 주의할 점
(1) 초기 상태는 시도하지 않은것으로 간주한다.
(2) 블록을 합칠때는 2가지의 조건을 확인 한다.  
```  
합치고자 하는 대상이 이미 충돌한 블록인가
옮기고 있는 블록이 이미 충돌한 상태인가
```        

(3) 기울임에 따라 블록을 옮기는 순서를 달리 해야 한다.  
```
상 : (0, 0) -> (n, n)
하 : (n, 0) -> (0, n)
좌 : (0, 0) -> (n, n)
우 : (n, 0) -> (0, n)
```

#### 플로우 차트
(1) 기울임 탐색을 위한 BFS 알고리즘
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/12100_bfs.png)
(2) 블록을 옮기기 위한 알고리즘
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/12100_mvBall.png)

#### 구현 코드



```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef vector<vector<int>> table;
typedef vector<vector<bool>> crashed;
typedef pair<int, int> pos;
map<table, int> dist;

int dy[4] {-1,1,0,0};
int dx[4] {0,0,-1,1};
int n, ret;

void mvBlock(table& t, crashed& c, int sy, int sx, int i){
    int ny, nx;
    int next, prev;
    bool first = false;
    ny = nx = 0;

    while(true){
        ny = sy + dy[i];
        nx = sx + dx[i];

        if(ny < 0 || ny >= n)
            break;
        if(nx < 0 || nx >= n)
            break;

        if(t[ny][nx] == 0){
            swap(t[ny][nx], t[sy][sx]);
            sy = ny;
            sx = nx;
            continue;
        }else{
            next = t[ny][nx];
            prev = t[sy][sx];

            if(next == prev && !c[ny][nx] && !first){
                t[ny][nx] *= 2;
                t[sy][sx] = 0;
                first = true;
                c[ny][nx] = true;
                sy = ny;
                sx = nx;
                continue;
            }else{
                break;
            }

        }


    }

}



void move(table& t, int i){

    crashed c = crashed(n, vector<bool>(n, false));
    //up
    if(i == 0){
        for(int y = 0 ; y < n ; y++){
            for(int x = 0 ; x < n ; x++){
                if(t[y][x] == 0)
                    continue;
                mvBlock(t, c, y, x, i);
            }
        }
    }
    //down
    if(i == 1){
        for(int y = n-1 ; y >= 0 ; y--){
            for(int x = 0 ; x < n ; x++){
                if(t[y][x] == 0)
                    continue;
                mvBlock(t, c, y, x, i);
            }
        }
    }
    //left
    if(i == 2){
        for(int x = 0 ; x < n ; x++){
            for(int y = 0 ; y < n ; y++){
                if(t[y][x] == 0)
                    continue;
                mvBlock(t, c, y, x, i);
            }
        }
    }
    //right
    if(i == 3){
        for(int x = n-1 ; x >= 0 ; x--){
            for(int y = 0 ; y < n ; y++){
                if(t[y][x] == 0)
                    continue;
                mvBlock(t, c, y, x, i);
            }
        }
    }

}

int maxBlock(table t){
    int num = 0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            num = max(num, t[y][x]);
        }
    }
    return num;
}

void bfs(table start){
    queue<table> q;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        table current = q.front();
        q.pop();
        ret = max(ret, maxBlock(current));

        if(dist[current]>=5){
            continue;
        }

        for(int i = 0 ; i < 4 ; i++){
            table nt = current;
            move(nt, i);
            if(dist.count(nt)>0)
                continue;
            dist[nt] = dist[current] + 1;
            q.push(nt);
        }

    }
}

table build(){
    cin>>n;
    table t = table(n, vector<int>(n));
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < n ; x++){
            cin>>t[y][x];
        }
    }
    return t;
}


int main(int argc, const char * argv[]) {
    table start = build();
    bfs(start);
    cout<<ret<<endl;
    return 0;
}


```

### 깨달은 점
1. BFS 탐색을 통해 각 경우마다 다른 4가지의 상태를 만들어 볼 수 있다
2. 초기 상태롤 시도 한것으로 간주 해야 하는지 확인 하는 것이 매우 중요 하다 (정답여부 결정)
3. 문제의 한 문장이 2가지의 조건을 내포 한다는 것을 잘 파악 해야 한다.
  - 한번 이상 충돌 하면 안됨 :
      - 옮기고 있는 블록에서 2번 이상 충돌이 일어나면 안됨
      - 기존의 블록도 2번 이상 충돌을 허용하지 않음

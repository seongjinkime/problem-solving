![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/6087.png)
### Type : BFS

#### 접근
1. 위치, 거울의 갯수, 방향을 저장할 수 있는 구조체를 선언 한다.
2. 거울의 최소 설치 갯수를 저장할 수 있는 2차원배열을 선언한다
3. 다중의 구조체를 동시에 탐색시켜 최소의 Install 갯수를 구한다.  
4. 탐색 과정 중 방향이 달라진다면 거울을 설치 한다.  
5. BFS 탐색 조건 설정
    (1) 지정된 범위  
    (2) 벽이 아닌 지점
    (3) 더 많은 수의 거울을 설치 해야 하는지    

#### 주의사항

**1. 동일한 수의 거울을 설치할 때도 탐색을 실행 해야 한다.**
**2. 거울의 수를 증가 시킬 때 새로운 변수를 사용해야 한다.**  
  - 현재 구조체의 거울 설치수를 변경하면 안된다.


#### 코드 구현  

```cpp
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

#define INF 987654321
#define MAX 101
#define EMPTY '.'
#define WALL '*'
#define LASER 'C'

using namespace std;
typedef pair<int, int> pos;
//접근 1. 구조체 선언
typedef struct _WALKER{
    pos p;
    int install;
    int direction;

    _WALKER(pos _p, int _i, int _d){
        p = _p;
        install = _i;
        direction = _d;
    }

}walker;

int dy[4] {-1, 1, 0 ,0};
int dx[4] {0 ,0, -1, 1};

char map[MAX][MAX];
//접근 2. 거울 설치수를 저장할 2차원 배열 선언
int mirror[MAX][MAX];
int w, h;

bool inRange(int y, int x){
    return 0<= y && y < h && 0<=x && x< w;
}

void bfs(pos start, pos dest){
    int sy, sx, ny, nx;
    int install;
    queue<walker> q;

    //접근 3. 다중의 구조체를 방향별로 동시에 탐색
    //0=up, 1=down, 2=left, 3=right
    for(int direction = 0 ; direction<4 ; direction++){
        //position, install, direction
        walker w = walker(start, 0, direction);
        q.push(w);
    }
    mirror[start.first][start.second] = 0;

    while (!q.empty()) {
        walker current = q.front();
        sy = current.p.first;
        sx = current.p.second;
        install = current.install;
        q.pop();

        for(int newDirection = 0 ; newDirection < 4 ; newDirection++){
            ny = sy + dy[newDirection];
            nx = sx + dx[newDirection];
            int nInstall = install; //주의사항 2. 새로운 변수 사용 (기존 구조체의 값을 변경하지 않기 위함)

            //탐색 조건 1. 범위안에 있는지
            if(!inRange(ny,nx))
                continue;
            //탐색 조건 2. 통과 가능 여부
            if(map[ny][nx] == WALL)
                continue;
            //접근 4. 방향이 달라진다면 거울을 설치 한다.
            if(current.direction != newDirection)
                nInstall++;
            //탐색 조건 3. 기존보다 더 많은 거울을 설치해야 하는지
            if(mirror[ny][nx] < nInstall)
                continue;

            mirror[ny][nx] = nInstall;
            //position, install, direction
            walker nw = walker(pos(ny,nx), nInstall, newDirection);
            q.push(nw);
        }
    }


}

//초기화 및 입력
vector<pos> build(){
    vector<pos> starts;
    memset(visited, false, sizeof(visited));

    for(int y = 0 ; y < h ; y++){
        for(int x =0 ; x< w ; x++){
            cin>>map[y][x];
            mirror[y][x]=INF;
            //만약 LASER 가 발견된다면 list에 추가한다
            if(map[y][x] == LASER){
                starts.push_back(pos(y,x));
            }
        }
    }
    return starts;
}


int main(int argc, const char * argv[]) {
    pos start, dst;
    cin>>w>>h;

    //초기화 및 입력, 시작점 & 종료 지점
    vector<pos> lasers = build();
    start = lasers[0];
    dst = lasers[1];
    //탐색 진행
    bfs(start, dst);
    //목적지까지 가기위한 최소한의 거울 수 출력
    cout<<mirror[dst.first][dst.second]<<endl;
    return 0;
}

```

### 깨달은 점
**1. 최소한의 수를 구하기 위해 2차원 배열을 활용할 수 있다. (방문배열의 응용)**
**2. 기존값을 변경하지 않기 위해 새로운 변수를 사용해야 한다 (정답여부 결정)**

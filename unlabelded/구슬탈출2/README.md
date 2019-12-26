![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/13460.png)
### Type : 브루트포스, BFS

#### 1. 문제 분석
1. 최소한의 기울임 동작으로 빨간 구슬을 빼내는게 목적이다  
2. 실패 조건
    (1) 파란구슬만 빠졌을 경우
    (2) 파란구슬과 빨간공이 동시에 빠졌을 경우
    -> 순서와 상관 없이 **파란공이 구멍에 빠졌다면 실패**이다
3. 성공 조건
    (1) 빨간 구슬이 구멍에 빠졌을 경우

#### 2. 접근
1. 자료구조
    (1) 위치(y,x)를 저장할 pair<int, int> ball
    (2) 공 두개의 위치를 저장할 vector < ball > balls
    (3) 공의 탐색 위치와 거리를 저장할 map<balls, int> dist
    -> 많은 풀이에서 4차원 배열을 사용했지만 나는 좀더 직관적인 자료구조로 map을 사용 하였다  
    -> map에 각 공의 탐색 위치(상태)와 도달하기 위한 거리를 저장 할 수 있다.
</br>
2. 최소의 동작을 위한 BFS 탐색
    * 공 두개의 위치를 저장한 자료구조 balls를 담을 queue 선언
    * 탐색이 종료 될 때 까지  
        * 탐색 방향 선정 (Up, Down, Left, Right)
            * 탐색 방향으로 2개의 공을 굴리기
            * 만약 실패한 경우
              *  방향 바꿈
            * 만약 성공한 경우
              * 최소거리 반환
            * 만약 공이 겹쳤다면
              * Red ball의 움직임 > Blue Ball의 움직임
                * red ball 후퇴
              * Red ball의 움직임 < Blue Ball의 움직임
                * blue ball 후최
            * 이미 한번 이상 탐색한 위치 상태라면
                * 방향 바꿈
            * 새 탐색 위치 까지 도달 하기 위한 거리 = 현재 까지의 거리 + 1
            * q에 새 탐색 위치 추가  

        **후퇴: 가장 먼저 위치에 도달한 공을 그대로 두고, 늦게 도달한 공을 한칸 뺀다*
</br>
3. 공 굴리기  
    * 파라미터로 y의 진행방향, x의 진행 방향을 받는다  
    * 공을 한칸 굴려도 벽에 도달하지 않을때까지
      * 공을 한칸 굴린다
      * 움직임 + 1
      * 만약 현재 공이 구멍에 도달 한다면
        * 공 굴리기 종료  



#### 3. 주의사항

**(1) 실패할 경우 탐색을 종료 하는 것이 아니라 방향을 선회 한다**  
**(2) 한 지점에서 모든 방향으로 공을 굴려보면서 성공 여부가 가려질때 까지 탐색 한다**
**(3) 기존의 공을 굴리는 것이 아니라 새로운 변수로 공을 만들고 굴린다**

#### 4. 플로우차트  
(1) bfs 탐색
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/13460_bfs.png)
(2) move ball
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/13460_move.png)

#### 5. 코드 구현  

```cpp
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define MAX 11

using namespace std;
//접근 1. 자료구조 선언
typedef pair<int, int> pos;
typedef vector<pos> balls;
map<balls, int> dist;

int dy[4] {-1, 1, 0, 0};
int dx[4] { 0, 0,-1, 1};
char table[MAX][MAX];

pos hole;

//이미 한번이상 탐색한 상태인지 검사
bool vistied(balls b){
    return dist.count(b) > 0;
}

//접근 3. 공굴리기
void moveBall(pos& ball, int& move, int y, int x){
    while(table[ball.first + y][ball.second + x] != '#'){ //!
        if(table[ball.first][ball.second] == 'O')
            break;
        ball.first += y;
        ball.second += x;
        move++;
    }
}
//접근 2. 최소 움직임을 구하기 위한 BFS 탐색
int bfs(balls b){
    queue<balls> q;
    q.push(b);
    dist[b] = 0;

    while(!q.empty()){
        balls current = q.front();
        q.pop();

        if(dist[current]>=10)
            return -1;
        //한번의 위치당 4방향으로 기울여 본다
        for(int i = 0 ; i < 4 ; i++){
            //0 == Red, 1 == Blue
            pos nr = current[0];
            pos nb = current[1];
            int rDist = 0 ;
            int bDist = 0;

            moveBall(nr, rDist, dy[i], dx[i]);
            moveBall(nb, bDist, dy[i], dx[i]);

            //if fail
            if(nb == hole)
                continue;
            //if ok
            if(nr == hole)
                return dist[current]+1;
            //공이 겹쳤을때 늦게 도달한 공 후퇴
            if(nr == nb){
                if(rDist<bDist){
                    nb.first -= dy[i];
                    nb.second -= dx[i];
                }else{
                    nr.first -= dy[i];
                    nr.second -= dx[i];
                }
            }
            //새로운 탐색 위치(상태)
            balls nset = balls{nr, nb};
            //이미 한번 탐색한 위치라면 방향 선회
            if(vistied(nset)) continue;
            //거리 갱신 및 탐색 위치(상태) 추가
            dist[nset] = dist[current]+1;
            q.push(nset);
        }
    }
    //모든 경우에 실패 한다면 -1 반환
    return -1;
}
//입력
balls build(int w, int h){
    balls ret = vector<pos>(2);
    char ch;

    for(int y = 0 ; y < h ; y++){
        for(int x = 0 ; x < w ; x++){
            cin>>ch;
            if(ch == 'R'){
                ret[0] = pos(y, x);
            }else if(ch == 'B'){
                ret[1] = pos(y, x);
            }else if(ch == 'O'){
                hole = pos(y, x);
            }
            table[y][x] = ch;
        }
    }
    return ret;
}



int main(void){
    //입력 및 초디롸
    int w, h;
    cin>>h>>w;
    balls b = build(w, h);
    //BFS를 통해 최소 움직임 구함
    int mdist = bfs(b);
    cout<<mdist<<endl;

    return 0;
}

```

### 깨달은 점
1. BFS의 탐색을 모든 경우를 시도한다는 brute force에 접목 시킬 수 있다
2. 실패의 조건을 잘 분석 해야 한다
3. while 문 안에서 한칸 미리 굴려보고 가능 여부를 따져볼 수 있다
4. pair<int,int> 끼리 equal 여부를 판단할 수 있다.

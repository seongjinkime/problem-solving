![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/9328.png)
[문제 바로가기](https://www.acmicpc.net/problem/9328)
### Type : BFS

#### 접근
(1) 외부에서 접근 가능 하도록 지도 주의를 빈곳으로 둘러싼다.
(2) 한번의 BFS 당 열쇠를 한개 이상 찾거나 혹은 문서를 발견하는 일을 시도 한다.
(3) 만약 시도에 성공 했다면 다시 한번 BFS를 시도 한다.
(4) 만약 시도에 실패 했다면 BFS 를 종료 하고 다수의 시도에서 찾은 문서의 갯수를 출력 한다.
(5) BFS 탐색  
  * (1) 범위를 벗어나거나, 이미 방문 했거나, 벽이라면 탐색을 하지 않는다.
  * (2) 만약 탐색 지점에 문서가 있다면 카운트 하고, 성공한 시도로 정의한다.
  * (3) 만약 대문자 알파벳을 만났으나, 열쇠가 없다면 탐색을 하지 않는다.
  * (4) 만약 소문자 알파벳을 만났다면, 열쇠를 추가 하고 성공한 시도로 정의한다.

#### 플로우 차트
(1) BFS 탐색
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/9328_BFS.png)


#### 구현 코드



```cpp

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
#define EMPTY '.'
#define WALL '*'
#define DOCU '$'

using namespace std;

typedef pair<int, int> pos;
vector<vector<char>>table;
set<int> keys;
int dy[4]{-1, 1, 0, 0};
int dx[4]{0, 0, -1, 1};
int h, w;
int cnt;

bool inRange(int y, int x){
    return 0<=y && y < h && 0<=x && x<w;
}

bool bfs(){
    bool ret = false;
    int sy, sx, ny, nx;
    char ch;
    vector<vector<bool>> visted(h, vector<bool>(w, false));
    pos start(0, 0);
    queue<pos> q;
    q.push(start);
    visted[0][0] = true;

    while(!q.empty()){
        pos here = q.front();
        q.pop();
        sy = here.first;
        sx = here.second;

        for(int i = 0 ; i < 4 ; i++){
            ny = sy + dy[i];
            nx = sx + dx[i];
            if(!inRange(ny, nx) || visted[ny][nx] || table[ny][nx] == WALL)
                continue;

            ch = table[ny][nx];
            if(ch == DOCU){
                cnt++;
            }else if(ch != EMPTY){
                if(isupper(ch) && keys.count(ch-'A') == 0)
                    continue;
                else if(islower(ch)){
                    keys.insert(ch-'a');
                    ret = true;
                }
            }

            table[ny][nx] = EMPTY;
            visted[ny][nx] = true;
            q.push(pos(ny, nx));

        }
    }
    return ret;
}

void solve(){
    bool success = true;

    while (success) {
        success = bfs();
        //cout<<success<<endl;
    }
    cout<<cnt<<endl;
}

void build(){
    string kstr;
    keys.clear();
    cin>>h>>w;
    h+=2;
    w+=2;
    cnt = 0;
    table = vector<vector<char>>(h, vector<char>(w));

    for(int y = 1; y < h-1 ; y++){
        for(int x = 1 ; x < w-1 ; x++){
            cin>>table[y][x];
        }
    }
    for(int y = 0 ; y < h ; y++){
        table[y][0] = table[y][w-1] = EMPTY;
    }
    for(int x = 0 ; x < w ; x++){
        table[0][x] = table[h-1][x] = EMPTY;
    }

    cin>>kstr;
    if(kstr == "0")
        return;
    for(char k : kstr){
        keys.insert(k-'a');
    }
}

int main(int argc, const char * argv[]) {
    int t;

    cin>>t;
    for(int i = 0 ; i < t ; i++){
        build();
        solve();
    }


    return 0;
}

```

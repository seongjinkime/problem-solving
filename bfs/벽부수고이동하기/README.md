![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/2206.png)
### Type : BFS

#### 나의 접근1. 벽을 하나씩 없애고 탐색
1. 벽을 하나씩 없애면서 BFS 탐색을 한 후 가장 짧은 길이를 구한다
```cpp
 int breakWall(int y, int x){
     int distance;
     vector<vector<int>> table = map;
     table[y][x] = 0;
     distance = bfs(table);
     return distance;
 }
 
for(int y = 0 ; y < n ; y++){
    for(int x = 0 ; x < m ; x++){
         if(y == 0 && x == 0 && breakWall(y, x, len)){
             success++;
             continue;
         }
         
         if(map[y][x] == 1 && breakWall(y, x, len))
             success++;
     }
 }
 ...
```
0,0을 탐색 한 후 모든 벽을 없애보며 가장 짧은 길이를 구한다.  

2. 결과 : *시간 초과*
             최대 크기가 1,000 * 1,000 = 100,000개인데
             최악의 경우 벽이 99998개 생기므로 주어진 시간을 초과할 수 밖에 없다.

#### 나의 접근2. 인접 위치를 탐색 하면서 벽을 부순지 여부를 확인 한다 
1. y, x, broken을 저장 할 수 있는 구조체를 선언한다
```cpp
typedef struct _WALKER{
    int y, x, broken;
    
    _WALKER(int _y, int _x, int _b){
        y = _y;
        x = _x;
        broken = _b;
    }
}walker;
```

2.  벽을 한번도 부수지 않은 상태일때만 벽을 부순 후 queue에 Walker를 추가 한다.
```cpp
for(int i = 0 ; i < 4 ; i++){
    ny = cy + dy[i];
    nx = cx + dx[i];
    
    if(0 <= ny && ny < n && 0 <= nx && nx < m){

        if(map[ny][nx] == 0){
            map[ny][nx] = map[cy][cx] +1;
            q.push(walker(ny, nx, current.broken));
            
        }else if(map[ny][nx] == WALL){
            if(current.broken == 0){
                map[ny][nx] = map[cy][cx] + 1;
                q.push(walker(ny, nx, current.broken+1));
            }
            
        }
    }

}
```

3. 결과 : *틀렸습니다*
예시는 맞았다고 나오지만 반례가 존재 한다.
```
 6 4
 0000
 1110
 1000
 0000
 1111
 0000
 ```
 벽을 뚫고 map 전체를 탐색 할 수 있음에도 끝까지 도달하지 못한다.
 원인 : 벽을 부수고 탐색한 Walker들이 방문을 해버리기 때문에 벽을 부수지 않은 walker가 도달 하지 못한다.
 
 #### 답안 접근
 1. *중요* 벽을 부순 상태와 벽을 부수지 않은 상태를 나누어 탐색을 진행 한다.
```cpp
#define UNCRASHED 0
#define CRASHED 1
```

2. map과 별도로 방문 지점을 저장할 수 있는 3차원 배열을 만든다.
```cpp
int visited[2][MAX][MAX]; //벽을 부순 상태, 부수지 않은 상태
```

3. 2가지의 경우로 나누어 탐색을 진행  한다. 
```
1. 벽이 존재하지 않고 방문하지 않은 경우
    (1) 계속해서 탐색을 진행한다
2. 벽이 존재하지만 벽을 부순적이 없는 경우.
    (1) 벽을 부순 상태를 나타내는 배열에서 탐색을 시작한다
```

4. "3"번 항목을 코드로 옮기면 아래와 같다.
```cpp
if(map[ny][nx] == 0 && visited[status][ny][nx] == 0){
    visited[status][ny][nx] = visited[status][cy][cx] + 1;
    q.push(walker(ny, nx, status));
} //벽이 존재하지 않고 방문하지 않은 경우

if(map[ny][nx] == 1 && status == UNCRASHED){
    visited[CRASHED][ny][nx] = visited[UNCRASHED][cy][cx] + 1;
    q.push(walker(ny, nx, CRASHED));
}//벽이 존재하지만 벽을 부순적이 없는 경우
```

### 전략 BUILD
1. Action에 의해 상태가 달라지면 상태를 분리하여 탐색을 진행한다
2. 상태를 저장할 수 있는 구조체를 만들어 탐색을 진행 할 수 있다.


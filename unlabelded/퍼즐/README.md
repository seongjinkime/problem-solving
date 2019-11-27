![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/1525_1.png)
![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/1525_2.png)
### Type :  BFS

#### 나의 접근
1. 0을 기준으로 BFS 탐색을 실시 한다.  
2. 0에 인접한 원소들을 교환 하면서 인접 조건에 부합 하는지 검사 한다.

```cpp
//is range : 새로운 탐색 위치가 Table의 범위에 속하는지 검사
//visited : 이미 방문한 위치인지 검사
if(isRange(ny, nx) && visited[ny][nx] == 0){
    swap(table[cy][cx], table[ny][nx]);
    //조건에 부합하면 탐색 진행, 그렇지 않다면 원상 복귀
    if(qualified(cy, cx)){
        visited[ny][nx] = visited[cy][cx] + 1;
        q.push(pos(ny, nx));
    }else{
        swap(table[cy][cx], table[ny][nx]);
    }
}
```    

3. 인접 조건 검사  
좌, 우 위치의 값이 0이 아니고, 차이가 1이상 나면 인접하지 않은 것으로 판단.
```cpp
int nx = newPos[i]; //nx = x-1, x+1
if(isRange(y, nx) && table[y][nx] != 0){
    int b = table[y][nx];
    if (abs(a-b) != 1)
        return false;
```


#### 결과 : **틀렸습니다** (21% 통과)    
원인  
- 인접 조건 검사의 정확도가 부실함.  
- 알고리즘의 정확한 정의와 풀이 방법이 미비함


#### 모범답안 접근 및 풀이

1. 0 대신 9를 삽입 하고 목표물을 설정 한다
```
1 9 3
4 2 5
7 8 6
```
```
Target = 123456789
```

2. 문자열 BFS 트리 탐색을 통해 주어진 상태로 부터 목표 상태까지 도달 할 수 있는 최소 거리를 구한다.  
    ```
    Tree Example
                 123495786
    193425786    913425789
                 139425789
    ```
    (1) 위치 및 현재 상태 파악
    ```cpp
    string current = q.front();
    int idx = current.find('9');
    int y = idx / len;
    int x = idx % len;
    ```
    **2차원 배열을 사용하지 않고 몫과 나머지를 통해 y와 x 값을 도출 할 수 있다**

    (2) 만족한 범위 내에서 요소의 순서를 바꾼 새로운 문자열(상태)을 생성 한다.
    ```cpp
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(0<=ny && ny < len && 0 <= nx && nx < len){
        string tmp = table;
        swap(tmp[y * 3 + x], tmp[ny * 3 + nx]);
    ```
    (3) 기호와 구간 합이 다를경우 false를 반환 한다.
    - 만약 아직 한번도 방문한 적이 없는 상태일 경우 탐색을 진행 한다.  
    - 탐색 순서를 현재 탐색 순서 +1 로 갱신한다.
    ```cpp
    if(visited.count(tmp)==0){
      visited[tmp] = visited[table]+1;
      q.push(tmp);
      cnt++;
    }
    ```
    **상태 방문 순서를 기록하기 위해 map<string, int> 자료 구조를 사용한다**

    (4) 만약 현재 상태가 목표 상태와 동일 하다면 방문 순서를 반환 한다.
    ```cpp
    if(current==target){
        return visited[table];
    }
    ```

#### 주요 코드
```cpp
int bfs(string start){
    queue<string> q;
    map<string, int> visited;
    visited[start] = 0;
    q.push(start);
    int cnt = 0;
    while(!q.empty()){
        string current = q.front();
        //cout<<table<<endl;
        int idx = current.find('9');
        int y = idx / len;
        int x = idx % len;
        q.pop();
        if(table==target){
            return visited[table];
        }
        for(int i = 0 ; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0<=ny && ny < len && 0 <= nx && nx < len){
                string tmp = current;
                swap(tmp[y * 3 + x], tmp[ny * 3 + nx]);
                if(visited.count(tmp)==0){
                    visited[tmp] = visited[current]+1;
                    q.push(tmp);
                    cnt++;
                }
            }
        }
    }
    return -1;
}
```

### 깨달은 점
1. **문자열 상태 탐색을 통해 BFS를 실시 할 수 있다**
2. 상태 방문을 위해 map 자료구조를 활용 할 수 있다.
3. 2차원 배열 대신 몫과 나머지를 활용할 수 있다.

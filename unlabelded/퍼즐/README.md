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
- 순열 생성 시간 복잡도는 n! 이다.  
- 최악의 경우 20! (2432902008176640000)번 을 계산 해야 한다.
- 실제로 동작할 경우 하루가 넘게 걸리는 시간이다.


#### 모범답안 접근 및 풀이

1. 조건을 만족할 때만 순열 생성을 이어 나간다.
```cpp
for(int i = 0 ; i < nums.size() ; i++){
    permutation.push_back(nums[i]);
    if(qualified(cnt)){ //cnt는 순열의 크기
        perm(cnt+1);
    }
    permutation.pop_back();
}
```
**순열을 생성 하고 난 뒤 조건 검사를 하는 것과 대비 적이다.**  
**경우의 수를 확연히 줄일 수 있다.**    

2. 기호 매칭  
    (1) 기호 Table 생성  
    ```
     n=4
     (0,0) (0,1) (0, 2) (0, 3)
           (1,1) (1, 2) (1, 3)
                 (2, 2) (2, 3)
                        (3, 3)
    ```  
    - 기호를 순서대로 배치 할 수 있다.  
    ```
    ex) (0,0) = 첫번째 기호, (0, 1) = 두번째 기호 ...  
    ```

    (2) (row, col)의 구간 합을 차례대로 구한다.  
    ```cpp
      //idx = 순열의 크기
      for(int row = idx ; row >= 0 ; row--)
        sum += permutation[idx];
    ```  

    (3) 기호와 구간 합이 다를경우 false를 반환 한다.
    ```cpp
    if(op[row][col] == '+' && sum <= 0)
      return false;
    if(op[row][col] == '-' && sum >= 0)
      return false;
    if(op[row][col] == '0' && sum != 0)
      return false;
    ```


#### 주요 코드
```cpp
bool qualified(int col){
    int sum = 0;
    int idx = col;
    for(int row = col ; row >= 0 ; row--){
        sum += permutation[idx];
        if(op[row][col] == '+' && sum <= 0)
            return false;
        if(op[row][col] == '-' && sum >= 0)
            return false;
        if(op[row][col] == '0' && sum != 0)
            return false;
        idx--;
    }
    return true;
}

void perm(int cnt){
    if(cnt == n){
        for(int i = 0 ; i < permutation.size() ; i++){
            cout<<permutation[i]<<" ";
        }
        exit(0);

    }
    for(int i = 0 ; i < nums.size() ; i++){
        permutation.push_back(nums[i]);
        if(qualified(cnt)){
            perm(cnt+1);
        }
        permutation.pop_back();
    }
}
```

### 깨달은 점
1. 구간 합을 (0, 0), (0, 1)... 이 아닌 (i, i), (i-1, i), (i-2, i)... 로 구할수도 있다.
2. **기호 매칭으로 완전 탐색을 실시 할 수 있다.**  
3. 순열 생성 이전에 조건을 검사하면 수행 시간을 확연히 줄일 수 있다. (경우의 수 감소)

![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/10942.png)
### Type :  다이나믹 프로그래밍

#### Palindrome 이란?
- 앞에서 읽어도, 뒤에서 읽어도 동일한 문자 혹은 수를 의미 한다.  
- ex) aba, anna, 121, 12321

#### 나의 접근
1. 2차원 배열에 구간 당 펠린드롬 여부를 저장 한다.  
```
(1, 1) (1, 2) (1, 3)
       (2, 2) (2, 3)
...
```  

(1) 모든 s, e 구간을 탐색 하며 배열의 일부분을 잘라 Palindrome 여부를 검사한다.
```cpp
for(int s = 1 ; s<=n ; s++){
    for(int e = s ; e<=n ; e++){
        part = vector<int> (nums.begin()+s, nums.begin()+e+1); //구간 배열 생성
        table[s][e] = palindrome(part); //펠린드롬 여부 저장
    }
}
```  

(2) 원본 배열과, 뒤집어진 배열이 일치하는지 검사하여 팰린드롬 여부를 검사 한다.  
```cpp
bool palindrome(vector<int> arr){
    vector<int> rev (arr.rbegin(), arr.rend());
    return arr==rev;
}
```
** Tip : rbegin(), rend() 함수를 통해 배열을 뒤집을 수 있다. **  

(3) 입력이 들어오면 미리 저장된 배열의 팰린드롬 여부를 출력 한다.
```cpp
for(int i = 0 ; i < m ; i++){
    scanf("%d %d", &s, &e);
    printf("%d\n", table[s][e]);
}
```

**Tip : rbegin(), rend() 함수를 통해 배열을 뒤집을 수 있다.**

#### 결과 : **시간 초과**  

2. 2차원 배열에 입력 배열의 일부분을 구간별로 저장 한다.  
```
//s, e : 순방향 구간  
//e, s : 역방향 구간  
(1, 1) (1, 2) (1, 3)
(2, 1) (2, 2) (2, 3)
(3, 1) (3, 2) (3, 3)
```  

(1) 2차원 배열 Build  
- 모든 s, e 구간을 탐색 하며 배열의 일부분을 자른 구간 배열을 생성 한다.
- 구간 배열을 뒤집은 역방향 배열을 생성 한다.  
- (s,e) , (e,s) 구간에 각각의 배열을 저장한다.

```cpp
for(int s = 1 ; s<=n ; s++){
  for(int e = s ; e<=n ; e++){
      part = vector<int> (nums.begin()+s, nums.begin()+e+1);
      rev = vector<int> (part.rbegin(), part.rend());
      table[s][e] = part;
      table[e][s] = rev;
  }
}    
```

(2) 입력이 들어오면 (s,e), (e,s) 구간 배열이 동일한지 여부를 검사 한다.  
```cpp
for(int i = 0 ; i < m ; i++){
    cin>>s>>e;
    cout<<(table[s][e] == table[e][s])<<endl;
}
```
#### 결과 : **메모리 초과**  

#### 모범답안 접근 및 풀이

1. 필요한 탐색  
    (1) n+1, n+2 대각선  
        - 온전히 뜯을 수 있는 위치의 스티커는 n+1 혹은 n+2칸의 대각선에 위치한 스티커 이다  
          ex) 50 -> 50 , 50 -> 70  

2. 불필요한 탐색  
    (1) 동일한 row에 위치한 n+2칸의 스티커는 대각선을 거쳐 탐색하는 것보다 클 수 없다  
       ex) (50 + 100) < (50 + 50 + 100)  
    (2) n+3 대각선에 위치한 스티커는 3보다 작은칸의 대각선을 거쳐 탐색하는 값 보다 클 수 없다  
       ex) (50+10) < 50 + 50 + 100 + 10)  

3. 점화식 도출  
    필수적인 탐색만 사용하여 배열의 값을 채워 나간다.  
    ```cpp
    dp[0][n] = max(dp[1][n-1], dp[1][n-2]) + cost[0][n]
    dp[1][n] = max(dp[0][n-1], dp[0][n-2]) + cost[1][n]
    ```

4. 초기화  
   (1) dp 배열 탐색이 cost부터 시작되도록 초기화 한다.
   ```cpp
    dp[0][1] = cost[0][1];
    dp[1][1] = cost[1][1];
   ```
   (2) Index Error를 방지 하고 순차적인 탐색이 가능하도록 0번째 칸을 0으로 초기화 한다.  
   ```cpp
    dp[0][0] = dp[1][0] = 0;
   ```    

#### 주요 코드
```cpp
for(int i = 2 ; i <= n ; i++){
    dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + cost[0][i];
    dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + cost[1][i];
}
```

### 깨달은 점
1. 탐색할 경우가 n에 비례하여 많아질 경우에는 필요한 탐색 경로와 의미없는 탐색 경로를 규정 해야 한다.
2. 생각한 탐색 경로를 그려놓고 어떤것이 의미 있고 어떤것이 의미 없는지 생각하면 힌트를 얻을 수 있다.
3. 0을 초기 값으로 두어 순차적인 탐색을 가능 하도록 만들 수 있다.

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
  **Tip : rbegin(), rend() 함수를 통해 배열을 뒤집을 수 있다.**  

  (3) 입력이 들어오면 미리 저장된 배열의 팰린드롬 여부를 출력 한다.
  ```cpp
  for(int i = 0 ; i < m ; i++){
      scanf("%d %d", &s, &e);
      printf("%d\n", table[s][e]);
  }
  ```

 **결과 : 시간 초과**  

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
  **결과 : 메모리 초과**  

#### 모범답안 접근 및 풀이

1. 펠린드롬 검사  
- 양끝의 간격을 좁혀가며 원소가 동일한지를 검사 한다.
- start<end 조건을 만족하는 동안 start를 증가 시기고, end를 감소시킨다.  
- 만약 array[start] 와 array[end]가 동일하지 않다면 false를 반환 한다.  

2. Memoization *불필요한 검사 줄이기*
- 모든 구간에 대해 펠린드롬 검사를 하는 것엔 중복된 검사가 존재 한다.  
  ```
  (1) 만약 array[start] 와 array[end]가 동일하고  
  (2) start+1, end-1 구간이 이미 펠린드롬이라고 판정 된다면
  => start와 end 구간도 펠린드롬이다.
  ```
  ```
  ex) 1 (2 2) 1
  ```

3. 구간의 길이를 서서히 넓혀가면서 팰린드롬 여부를 사전확인 한다.  
- 길이가 1일때는 모든 원소가 팰린드롬 이다.  
```cpp
for(s = 0 ; s < n ; s++){
    palindrome[s][s] = 1;
}
```
- 길이가 2일때는 start 와 start+1 이 동일하다면 팰린드롬이다.  
```cpp
for(int s = 0 ; s < n-1 ; s++){
  e = s+1;
  if(nums[s] == nums[e]){
    palindrome[s][e] = 1;
  }
}
```
- 길이가 3이상일때는 Memoization을 활용 한다.  
```cpp
for(int len = 2 ; len < n ; len++){
    for(s = 0 ; s < n-len ; s++){
        e = s + len;
        if(nums[s] == nums[e] && palindrome[s+1][e-1]){
            palindrome[s][e] = true;
        }
    }
}
```
**start 는 n-len 만큼만 증가시켜도 된다**

4. 사전에 확인된 배열을 통해 팰린드롬 여부를 출력한다.  
```cpp
void solve(){
    scanf("%d", &m);
    int s, e;
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", palindrome[s-1][e-1]);
    }
}
```
**입력은 시작점의 기준이 1이기 때문에 1을 감소시켜 준다**
**시간단축을 위해 cin, cout 대신 scanf와 printf를 사용한다**


#### 주요 코드
```cpp
void preCheck(){
    int s, e;
    //len = 1
    for(s = 0 ; s < n ; s++){
        palindrome[s][s] = 1;
    }
    //len = 2
    for(int s = 0 ; s < n-1 ; s++){
        e = s+1;
        if(nums[s] == nums[e]){
            palindrome[s][e] = 1;
        }
    }

    //len > 3
    for(int len = 2 ; len < n ; len++){
        for(s = 0 ; s < n-len ; s++){
            e = s + len;
            if(nums[s] == nums[e] && palindrome[s+1][e-1]){
                palindrome[s][e] = true;
            }
        }
    }
}

void build(){
    nums = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &nums[i]);
    }
}

void solve(){
    scanf("%d", &m);
    int s, e;
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", palindrome[s-1][e-1]);
    }
}

```

### 깨달은 점
1.
2.

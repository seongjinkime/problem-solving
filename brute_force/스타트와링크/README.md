![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/14889.png)
### Type : 브루트포스

#### 나의 접근
1. 팀을 나누기 위한 경우의 수를 순열을 통해 탐색 했다
```
 a) 1 2 3 4 5 6
 b) 1 2 3 4 6 5
 c) 1 3 4 5 4 6
 ...
```
2. 생성된 순열을 2개의 Vector로 분리 한다  
```
Team A) 1 2 3
Team B) 4 5 6
```
3. 각 Vector 별로 가능한 모든 순서 쌍의 점수 합을 계산 한다
```cpp
int score(vector<int> members){
    int sum = 0;
    int pa, pb;
    
    for(int i = 0 ; i < members.size() ; i++){
        pa = members[i];
        for(int j = 0 ; j < members.size() ; j++){
            if(i==j)
                continue;
            pb = members[j];
            sum += table[pa][pb];
        }
    }
    return sum;
}
```

4.  2개 Vector의 점수 차이를 구하고 최소 값을 갱신 한다
```cpp
return abs(scoreA-scoreB);
```

5. 결과 : <span style="color:red">시간초과</span>
 
 
#### 시간초과의 원인
1. 동일한 조합을 2번씩 탐색 한다
```
ex) {1, 2, 3} - {4, 5, 6}, {4, 5, 6} - {1, 2, 3}
```
|a - b|, |b- a|는 순서 상관 없이 동일 하므로 2번 계산할 필요가 없다.
_string 과 set을 이용하여 중복을 피하는 시도를 해보았지만 시간 초과는 여전했다_

2. Team 멤버들의 가능한 모든 쌍을 검사할 때   inner loop을 0부터 시작 하지 않아도 된다
```cpp
//많은 계산 횟수 
for(int i = 0 ; i < members.size() ; i++){
    for(int j = 0 ; j < members.size() ; j++){
        if(i==j)
            continue;
        sum += table[pa][pb];
    }
}
//적은 계산 횟수  [a][b] + [b][a]
for(int i = 0 ; i < members.size() ; i++){
    for(int j = ㅑ+1 ; j < members.size() ; j++){
        if(i==j)
            continue;
        sum += table[pa][pb] + table[pb][pa];
    }
}

```
  
#### 답안 및 주요 코드
1. n의 절반 크기로 조합을 만든다. 조합은 중복이 발생하지 않는다.
```cpp
void dfs(int here, int cnt){
    if(cnt == n/2){
    ...
    }
    return;
}
```
2. 조합 생성후 선택된 인자와 그렇지 않은 인자들을 Start와 Link팀으로 나눈다
  ```cpp
for(int i = 0 ; i < n ; i++){
  if(selected[i])
      start.push_back(i);
  else
      link.push_back(i);
}
  ```
3. start 팀과 link 팀의 능력치를 모두 합산 한다
  ```cpp
for(int i = 0 ; i<start.size() ; i++){
  int sy, sx, ly, lx;
  for(int j = i+1 ; j<start.size() ; j++){
      sy = start[i]; sx = start[j]; //start member
      ly = link[i]; lx = link[j];   //link member
      
      //add stat of member
      scoreA += table[sy][sx] + table[sx][sy];
      scoreB += table[ly][lx] + table[lx][ly];
  }

}
  ```
 4. 점수 차이중 가장 작은 값을 구한다  
 
 
 #### Code
 ```cpp
int compare(){
     //seperate team
     vector<int> start, link;
     int scoreA, scoreB;
     
     scoreA = scoreB = 0;
     
     for(int i = 0 ; i < n ; i++){
         if(selected[i])
             start.push_back(i);
         else
             link.push_back(i);
     }
     for(int i = 0 ; i<start.size() ; i++){
         int sy, sx, ly, lx;
         for(int j = i+1 ; j<start.size() ; j++){
             sy = start[i]; sx = start[j]; 
             ly = link[i]; lx = link[j];
             
             scoreA += table[sy][sx] + table[sx][sy];
             scoreB += table[ly][lx] + table[lx][ly];
         }
     }

     return abs(scoreA-scoreB);
}


void dfs(int here, int cnt){
     if(cnt == n/2){
         int diff = compare();
         ret = min(ret, diff);
         return;
     }
     
     for(int i = here; i< n ;i++){
         if(!selected[i]){
             selected[i]=true;
             
             dfs(i, cnt+1);
             selected[i]=false;
             
         }
     }
}

```


### 전략 BUILD
1. 가능한 멤버 경우의 수를 조합 탐색 과정을 통해 만들어 낼 수 있었다
2. 선택된 인자와 그렇지 않은 인자를 구분할 수 있는 좋은 문제였다
3. 적절히 무엇을 나누어~ 의 뉘앙스의 문제가 나오면 조합과 이분을 생각해보자.


![Problem](https://github.com/seongjinkime/problem-solving/blob/master/images/1149.png)

### Type : 다이나믹 프로그래밍

#### 나의 접근
1. 가장 작은 값만을 찾아나가면서 최소값을 구한다
```
 26 40 83  26
 49 60 57  60
 13 89 99  13
 ...
```

2. 연속해서 동일한 색상이 칠해지면 안되므로 color  값을 저장 한다
```cpp
colored = i;
```

3. n 개의 집을 색칠할 비용을 구하는 점화식을 아래와 같이 세웠다.
```cpp
dp [n] = dp[n-1] + min(table[i]) // i!=coloered
```

4.  color를 갱신하며 최소 값을 찾아나가는 코드
```cpp
int getMin(int row){
    int ret = MAX;
    for (int i = 0 ; i < 3 ; i++){
        if(i==colored) //이미 칠해진 컬러면 건너뛴다
            continue;
        if(ret > table[row][i]){
            ret = table[row][i]; //가장 작은 값을 갱신 한다
            colored = i;         //색칠한 color를 저장 한다
        }
    }
    return ret;
}

void solve(){
    colored = -1;
    dp[0] = getMin(0);
    for(int i = 1 ; i < n ; i++){
        dp[i] = dp[i-1] + getMin(i); //직전에 들었던 비용 + 기존에 색칠된 컬러 외에 가장 저렴한 색칠 비용
    }
    cout<<dp[n-1]<<endl;
}
```

5. 결과 : 오답

6. 반례
```
|R|G|B|
|------|----|----|
|1001|999|999|
|999|1000|1000|
|1|1001|1001|

```
Row 마다 최소값을 찾아나가면 G -> R -> G  (999 + 999 + 1001 = 2999)  
하지만 더 작은 경우가 존재 함  G -> B -> R   (999 + 1000 + 1 = 2001)  

어떤 방식으로 문제를 해결할 코드를 작성해야 할지 몰라 실패로 끝남 

#### 답안 및 주요 코드
1. 접근
(a) 기본 아이디어
```
앞집에서 R을 선택하면 고를 수 있는 후보는 G 혹은 B
앞집에서 G를 선택하면 고를 수 있는 후보는 R 혹은 B
앞집에서 B를 선택하면 고를 수 있는 후보는 R 혹은 G
```
(b)  두개의 후보중 최소 비용과 선택한 컬러의 비용 합산
```
집 2가 R이 되려면 (직전 G의 누적 비용, 직전 B의 누적 비용중 작은 값) + 집2의 R 비용
집 2가 G가 되려면 (직전 R의 누적 비용, 직전 B의 누적 비용중 작은 값) + 집2의 B 비용
집 2가 B가 되려면 (직전 R의 누적 비용, 직전 G의 누적 비용중 작은 값) + 집2의 B 비용
```

```
ex ) table[2][R] = cost[2][R] + min(table[1][G], table[1][B]) 
```
*누적 비용은 동일한 방식으로 최소값을 찾아 누적 해온 비용 이다*
*하나의 컬러의 비용만 누적한것이 아니다*

2. 점화식
```
dp[n][0] = min(dp[n-1][1], dp[n-1][2]) + cost[n][0];
dp[n][1] = min(dp[n-1][0], dp[n-1][2]) + cost[n][1];
dp[n][2] = min(dp[n-1][0], dp[n-1][1]) + cost[n][2];
```
*각 3가지의 경우에 대하여 모두 계산해준다.
 
 #### Code
 ```cpp
void solve(){
    int ret;
    
    for(int i = 0 ; i < 3 ; i++)
        dp[0][i] = cost[0][i];
    
    for(int i = 1 ; i< n ; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    ret = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    cout<<ret<<endl;
    
}

```


### 전략 BUILD
1.  row, col 별로  최소값을 구하여 저장 할 수 있다
2. 수없이 많은 분기를 도표로 해결 할 수 있는 문제 였다.
3. 각 경우 별로 모든 경우의 수를 계산 하는 경우에는 2차원 Array를 사용해보자.

[문제링크](https://www.acmicpc.net/problem/1149).

### 연관문제
1. [123 더하기 5](https://www.acmicpc.net/problem/15990).
2. [쉬운계단수](https://www.acmicpc.net/problem/10844).


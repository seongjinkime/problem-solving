![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/6064.png)
[문제 바로가기](https://www.acmicpc.net/problem/6064)
### Type : 브루트 포스

#### 접근
1. 나열해보기 (ex : m =  5, n = 7)
1: < 1, 1 >   7 : < 2, 7 >        
2: < 2, 2 >   8 : < 3, 1 >
3: < 3, 3 >   9 : < 4, 2 >
4: < 4, 4 >   10: < 5, 3 >
5: < 5, 5 >   11: < 1, 4 >
6: < 1, 6 >   12: < 2, 5 >

2. 불필요한 연산 제거
  * 문제의 목표는 x와 y가 모두 일치하는 해를 찾는 것이다  
  * M * N 의 최대값은 40000 ^ 2 = 16억 이므로 1씩 증가시키면 시간 초과 발생  
  * x 가 일치하지 않은 해를 건너띄어 연산수 감소 시켜야 함

3. 규칙 찾기 및 해 건너 띄기  
  * x는 m 주기로 나타난다
  * y는 n 주기로 나타난다
  * year를 m, n으로 나눈 값이 x와 y 가 된다  
  * year를 m 만큼 증가시켜 바로 다음 주기의 해를 검사 한다  

4. 검사 방법
  * day가 만약 y와 일치한다면 해를 출력 한다
  * x, y 가 모두 0이 되는 최소 공배수의 해를 만나면 -1을 출력 한다  

#### 플로우 차트
1. 규칙에 따라 x와 y가 일치하는 해를 찾는 solve
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/6064_solve.png)

2. limit 해를 구하는 최소 공배수와 최대 공약수  
  * 최소 공배수
    ```cpp
    return a * b / gcd(a,b);
    ```
  * 최대 공약 수

![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/6064_gcd.png)
#### 구현 코드



```cpp

#include <iostream>

using namespace std;

int gcd(int a, int b){
    int numA = max(a, b);
    int numB = min(a, b);
    while (numB != 0) {
        int rem = numA % numB;
        numA = numB;
        numB = rem;
    }
    return numA;
}

int lcm(int a, int b){
    return a*b / gcd(a, b);
}

int solve(int m, int n, int x, int y){
    int year, day, limit;
    limit = lcm(m, n);
    year = x%m;

    if(year == 0){
        year = m;
    }

    while(year<=limit){
        day = year % n;
        if(day == 0)
            day = n;

        if(day == y)
            return year;

        year += m;

    }
    return -1;

}
int main(int argc, const char * argv[]) {
    int m, n, x, y;
    int t;
    cin>>t;

    for(int i = 0 ; i < t ; i++){
        cin>>m>>n>>x>>y;
        cout<<solve(m,n,x,y)<<endl;
    }

    return 0;
}

```

### 깨달은 점
1. 유클리드 호제법으로 빠른시간에 최소공배수를 구할 수 있다
2. 나머지 문제의 활용, 주기를 통하여 idx를 구할 수 있음  

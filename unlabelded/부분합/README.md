![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/1806.png)
[문제 바로가기](https://www.acmicpc.net/problem/1806)
### Type : 브루트포스

#### 접근
1. 완전 탐색으로 구현하면 시간초과 발생하는 문제
  - o(n^2)
2. 분할정복을 하면 중간값을 계산하지 못해 틀리는 문제  
3. 특정 구간을 정하여 작업을 수행할 수 있는 [투포인터 알고리즘](https://www.acmicpc.net/problem/1806)을 활용 해야 하는 문제이다.
    - 투 포인터 알고리즘은 시간복잡도가 o(n)이다

4. 투포인터 알고리즘 이란?  
    -  두개의 피봇(start, end)을 적절히 움직여 배열의 특정 구간을 지정하는 것이다  
    -  end를 한칸 뒤로 옮긴 후에는 sum에 arr[end]를 더해준다
    -  start를 한칸 뒤로 옮긴 후에는 sum에서 arr[start]를 빼준다  
</br>

5. 투포인터 알고리즘 진행 방식
* start, end를 0으로 초기화 한다.
* sum 은 배열의 첫번째 원소로 초기화 한다.  
* start가 end 이하이며 end가 n 미만 일동안
  * 만약 sum 이 s 미만이라면
    * end를 한칸 뒤로 옮긴다
    * sum에 arr[end]를 더해준다
  * 만약 sum이 s와 동일하다면
    * 경우의 수를 1 증가 시킨다.
    * end를 한칸 뒤로 옮긴다.
    * sum에 arr[end]를 더해준다
  * 만약 sum이 s보다 크다면
      * sum에서 arr[start]를 빼준다
      * start를 한칸 뒤로 옮긴다.
          * 탐색 종료
      * 만약 start가 end를 초과하면서 start가 n 미만이라면
          * sum을 arr[end]로 초기화
          * end = start

*start가 end를 초과 하는 경우 n = 14, arr = [1,2,3,15,1]*

#### 구현 코드



```cpp
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

vector<int>arr;
int n,s;
int ret;


void solve(){
    int low, high;
    int sum;

    low = high = 0;
    sum = arr[0];
    //투포인터 알고리즘 진행
    while(low<=high && high<n){
        if(sum<s){
            high++;
            sum += arr[high];
        }else if(sum == s){
            //high-low+1 = 구간의 길이
            ret = min(ret, high-low + 1);
            high++;
            sum += arr[high];
        }else if(sum > s){
            ret = min(ret, high-low+1);
            sum -= arr[low];
            low++;
            if(low>high && low<n){
                high = low;
                sum = arr[high];
            }
        }
    }

    if(ret == INF){
        cout<<0<<endl;  //n이상의 수를 만들지 못할 경우
    }else{
        cout<<ret<<endl; //답을 찾은 경우
    }
}

void build(){
    ret = INF;
    arr = vector<int>(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }
}

int main(void){
    //입력 및 초기화
    scanf("%d %d", &n, &s);
    build();
    //문제 해결 진행
    solve();

    return 0;

}

```

### 깨달은 점
1. 배열의 부분 구간을 지정하는데 투 포인터 알고리즘이 사용될 수 있다(o(n))
2. 특정한 경우 시작점이 끝점을 초과할 수도 있다.

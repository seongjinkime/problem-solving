![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/12101.png)
[문제 바로가기](https://www.acmicpc.net/problem/12101)
### Type : 다이나믹 프로그래밍, 탐색

#### 접근
1. 1,2,3 더하기 1에서 약간의 응용이 들어간 문제다.  
  **재귀 탐색 부분에서 수를 추가할때마다 vector에도 숫자를 추가 해준다**  
  **탐색 함수를 호출할 때 숫자를 추가한 vector를 넘겨 준다**  
  **1,2,3 으로 n을 만들 수 있을때 2차원 vector에 vector를 추가 한다.**  
  **문제에 주어진대로 정렬을 한다**
  **만약 2차원 배열의 길이가 k를 넘는다면 -1, 그렇지 않다면 결과 출력**

#### 구현 코드



```cpp

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 12


using namespace std;

int arr[12];
//2차원 배열
vector<vector<int>> lists;
int n, k;

bool comp(vector<int> a, vector<int> b){
    int idxA, idxB;
    idxA = idxB = 0;
    //2개의 숫자가 틀린 지점 찾기
    while(a[idxA] == b[idxA]){
        idxA++;
        idxB++;
    }
    //크기 비교 결과 반환(사전 순)
    return a[idxA]<b[idxB];
}
//재귀 탐색 함수
int find(int num, vector<int> nums){
    int ret = 0;

    if(num == n){
        //n을 만들 수 있다면 2차원 배열에 추가 한다
        lists.push_back(nums);
        return true;
    }
    if(num > n ){
        return false;
    }
    //탐색 호출 별로 새로운 수를 추가 하여 넘긴다
    for(int i = 1 ; i <= 3 ; i++){
        vector<int> next = nums;
        next.push_back(i);
        ret += find(num+i, next);
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    //초기화
    fill_n(arr, MAX, 0);
    cin>>n>>k;
    //탐색 및 2차원 리스트 사전순 정렬
    find(0, {});
    sort(lists.begin(), lists.end(), comp);
    //k번째 수가 없다면 -1 출력
    if(lists.size() < k){
        cout<<-1<<endl;
        return 0;
    }
    //결과 출력 진행
    vector<int> nums = lists[k-1];

    for(int i = 0 ; i < nums.size() ; i++){
        cout<<nums[i];
        if(i != nums.size()-1){
            cout<<"+";
        }
    }
    cout<<endl;


    return 0;
}


```

### 깨달은 점
1. 탐색 마다 vector를 활용하여 과정을 기록할 수 있다.

![Problem]((https://github.com/seongjinkime/problem-solving/raw/master/images/1062.png))
### Type : 브루트포스

#### 접근
1. 'a'~'z' 로 이루어진 k 개의 알파벳 조합을 생성한다  
    (1) 조합에 속한 알파벳은 배운것으로 가정한다  
    (2) 그렇지 않은 알파벳은 배우지 않은 것으로 가정한다.  

2. 말할 수 있는 단어 세기  
    (1) 입력으로 들어온 단어를 순회 한다.  
    (2) 만약 말할 수 있는 단어라면 숫자를 카운트 한다.  

3. 말할 수 있는 단어인지 검사  
    (1) 단어의 스펠링을 순회 한다.    
    (2) 만약 스펠링이 배우지 않은 알파벳이라면 'false'를 반환 한다.  
    (3) 모든 스펠링을 배웠다면 'true'를 반환 한다.  

#### 주의사항

**1. 문자열 입력에서 'anta'와 'tica' 를 제거한다**  
**2. 'a', 'n', 't', 'i', 'c'는 이미 배운것이라 가정한다**


#### 코드 구현  

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


#define MAX_N 51
#define MAX_K 27
#define EMPTY ""
using namespace std;
vector<string> inputs;
bool contains[MAX_K];
char alphabets[MAX_K];
bool selected[MAX_K];
int n,k;
int ret;

//접근 3. 말할수 있는 단어인지 검사
bool learned(string s){
    for(int idx = 0 ; idx < s.size() ; idx++){
        char ch = s[idx];
        if(!selected[ch-'a'])
            return false;
    }
    return true;
}

//접근 2. 말할 수 있는 단어세기
int completeNum(){
    int cnt = 0;
    for(int i = 0 ; i <  inputs.size() ; i++){
        if(learned(inputs[i])){
            cnt++;
        }
    }

    return cnt;
}

//접근 1. k개로 이루어진 알파벳 조합 생성
void dfs(int here, int cnt){
    if(cnt == k){
        int learnCnt = completeNum();
        ret = max(ret, learnCnt);
        return;
    }

    for(int there = here ; there < MAX_K ; there++){
        if(!selected[there]){
            selected[there] = true;
            dfs(there, cnt+1);
            selected[there] = false;
        }
    }
}

//주의사항 2. 사전에 배운 단어 확인
//k를 1씩 빼준다는 것에 유념하자
void preLearn(){
    char pre[5] {'a','c', 'i', 'n', 't'};
    for(int i = 0 ; i < 5 ; i++){
        char ch = pre[i];
        selected[ch-'a'] = true;
        k-=1;
    }
}

//주의사항 1. 'anta', 'tica' 제거
string filter(string s){
    return s.substr(4, (s.size()-8)); //anta 부터 시작하여 (anta+tica)를 뺀 갯수만큼의 글자를 반환
}

void build(){
    ret = 0;
    inputs = vector<string>(n);
    string s;

    //사전 초기화
    for(int idx = 0 ; idx < MAX_K ; idx++){
        alphabets[idx] = 'a'+idx;
    }

    //입력
    for(int i = 0 ; i < n ; i++){
        cin>>s;
        s = filter(s);//필터링
        inputs[i] = s;
    }

}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    preLearn(); //사전 확인 단어가 없으면 시간초과 발생
    build();//초기화 및 입력
    dfs(0, 0); //조합생성
    cout<<ret<<endl; //결과 출력
    return 0;
}

```

### 깨달은 점
1. 문제의 조건을 잘 확인 해야 한다. anta, tica를 배웠다고 확인하는 과정의 문제의 시간초과 여부를 결정지었다
2. substr을 통해 단어 필터링을 할 수 있다.

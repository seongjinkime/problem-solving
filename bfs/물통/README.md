![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2251.png)
[문제 바로가기](https://www.acmicpc.net/problem/2251)
### Type : BFS

#### 접근
(1) 가능한 모든 물통의 경우를 탐색 하기 위해 BFS 탐색을 실시 한다.
(2) 하나의 상태에 진입 할때마다 가능한 모든 경우로 물을 옮겨 본다.
(3) 한번 물을 옮길 때 마다 두가지 경우가 가능 하다.
```
* 다른 물통의 물을 전부 채울 수 있는 경우
* 붓는 물통의 물이 전부 비게 되는 경우
```
(4) 다른 물통의 물을 전부 채울 수 있는지 여부는 (size[dst] - water[dst]) < water[src] 로 검사 한다.

#### 플로우 차트
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2251_bfs.png)
![Problem](https://raw.githubusercontent.com/seongjinkime/problem-solving/master/images/2251_movewater.png)
#### 구현 코드



```cpp


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef vector<int> buckets;
buckets size;
vector<int>waters;

void moveWater(buckets& w, int src, int dst){
    if(w[src] > (size[dst] - w[dst])){
        w[src] -=(size[dst] - w[dst]);
        w[dst] = size[dst];
    }else{
        w[dst] += w[src];
        w[src] = 0;
    }
}

void bfs(buckets start){
    buckets nb;
    queue<buckets> q;
    q.push(start);
    set<buckets> visited;
    visited.insert(start);

    while(!q.empty()){
        buckets current = q.front();
        q.pop();

        if(current[0] == 0)
            waters.push_back(current[2]);

        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(i==j)
                    continue;
                nb = current;
                moveWater(nb, i, j);
                if(visited.count(nb)>0)
                    continue;
                visited.insert(nb);
                q.push(nb);
            }
        }
    }
}

void build(buckets& start){
    start = buckets(3, 0);
    size = buckets(3);
    for(int i = 0 ; i < 3 ; i++){
        cin>>size[i];
    }
    start[2] = size[2];
}

int main(int argc, const char * argv[]) {
    buckets start;
    build(start);

    bfs(start);
    sort(waters.begin(), waters.end());
    for(int w : waters)
        cout<<w<<" ";
    cout<<endl;
    //cout<<waters.size()<<endl;

    return 0;
}


```

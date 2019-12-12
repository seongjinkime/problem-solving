//
//  main.cpp
//  8111_0과1
//
//  Created by Kim Seong Jin on 2019. 12. 12..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <map>
#define FAIL "BARK"
#define MAX 20001

using namespace std;
map<int, char> numByRemain;
bool visited[MAX];
int parents[MAX];
int n;

void bfs(){
    queue<int> q;
    q.push(1);
    parents[1] = -1;
    visited[1] = true;
    numByRemain[1] = '1';
    while(!q.empty()){
        int current = q.front();
        q.pop();
        int newNums[2];
        newNums[0] = (current*10) % n;
        newNums[1] = (current*10+1) % n;
        for(int i = 0 ; i < 2 ; i++){
            int newNum = newNums[i];
            if(visited[newNum])
                continue;
            
            numByRemain[newNum] = i + '0';
            parents[newNum] = current;
            
            if(newNum==0)
                return;
            
            
            visited[newNum] = true;
            q.push(newNum);
        }
        
    }
}

void print(int num){
    if(num == -1){
        return;
    }
    print(parents[num]);
    cout<<numByRemain[num];
}


int main(void){
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        cin>>n;
        memset(visited, false, sizeof(visited));
        //numByRemain.clear();
        bfs();
        
        //memset(parents, 0, sizeof(parents));
        
        print(0);
        cout<<endl;
    }
    
    return 0;
}


/*

map<LL, int> len;
int n;

bool isLike(LL num){
    return num%10 == 1 && num%n == 0;
}

bool visited(LL d){
    return len.count(d) > 0;
}

void bfs(){
    LL newNum;
    
    queue<LL> q;
    len[1] = 1;
    q.push(1);
    
    while(!q.empty()){
        LL current = q.front();
        cout<<current<<" : "<<current%n<<endl;
        if(len[current]>=MAX){
            cout<<FAIL<<endl;
        }
        q.pop();
        if(n < current && current % n == 0){
            cout<<current<<endl;
            return;
        }

        LL newNums[2] {current*10, current*10 + 1};
        //string newNums[2] {current + '0', current+'1'};
        for(int i = 0; i<2 ; i++){
            LL newNum = newNums[i];
            if(!visited(newNum)){
                len[newNum] = len[current]+1;
                q.push(newNum);
            }
        }
        
    }
    
    
    cout<<FAIL<<endl;
}

//1001110111 : 112
//1010001100 : 112
int main(int argc, const char * argv[]) {
    n = 173;
    bfs();
    return 0;
}
*/

//
//  main.cpp
//  network
//
//  Created by Kim Seong Jin on 2019. 10. 18..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> computers;
vector<int>visted;

void dfs(int here){
    visted[here] = 1;
    
    for(int i = 0 ; i < computers[here].size() ; i++){
        if(here==i)continue;
        if(computers[here][i] == 1 && visted[i]==0){
            dfs(i);
        }
    }
}

int networks(){
    int cnt = 0;
    for(int i = 0 ; i < visted.size() ; i++){
        if(visted[i]==0){
            dfs(i);
            cout<<endl;
            cnt++;
        }
    }
    return cnt;
}


int solution(int n, vector<vector<int>> computs) {
    computers = computs;
    visted = vector<int>(n, 0);
    
    return networks();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 3;
    //vector<vector<int>> test {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    vector<vector<int>> test {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout<<solution(n, test)<<endl;
    return 0;
    
    
}

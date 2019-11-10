//
//  main.cpp
//  trainingSuit
//
//  Created by Kim Seong Jin on 2019. 10. 15..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int bestSolution(int n, vector<int> lost, vector<int> reserve){
    int answer = 0;
    vector<int>students(n+1, 0);
    for(int r : reserve)students[r]+=1;
    for(int l : lost)students[l]+= -1;
    for(int i = 1 ; i <= n ; i++){
        if(students[i]==-1){
            if(students[i+1]==1){
                students[i+1] = students[i] = 0;
            }else if(students[i-1]==1){
                students[i-1] = students[i] = 0;
            }
        }
    }
    
    for(int i = 1 ; i<=n ;i++){
        if(students[i]!=-1) answer++;
    }
    return answer;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    n -= lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int>::iterator finder;
    vector<int>toRm;
    
    for(int i = 0 ; i < lost.size() ; i++){
        finder = find(reserve.begin(), reserve.end() ,lost[i]);
        if(finder!=reserve.end()){
            reserve.erase(finder);
            toRm.push_back(i);
            //lost.erase(lost.begin()+i);
            n+=1;
        }
    }
    int rmCnt=0;
    for(int i = 0 ; i < toRm.size() ; i++){
        lost.erase(lost.begin()+toRm[i]-rmCnt);
        rmCnt++;
    }
    
    for(int l = 0 ; l < lost.size() ; l++){
        for(int r = 0 ; r < reserve.size() ; r++){
            if(lost[l]==reserve[r]+1 || lost[l]==reserve[r]-1){
                n+=1;
                reserve.erase(reserve.begin() + r);
            }
        }
    }
    return n;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int n = 7;
    vector<int>lost {2, 3, 4};
    vector<int>reserve {1, 2, 3, 6};
    cout<<solution(n, lost, reserve)<<endl;
    cout<<bestSolution(n, lost, reserve)<<endl;
    
    return 0;
}

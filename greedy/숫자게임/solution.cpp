//
//  main.cpp
//  numberGame
//
//  Created by Kim Seong Jin on 2019. 10. 23..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0;
    for(int j = 0 ; j < B.size() ; j++){
        if(A[i] < B[j]){
            i++;
            answer++;
        }
    }
    return answer;
}

int solution2(vector<int> A, vector<int> B) {
    int answer = 0;
    multiset<int, less<int>>s (B.begin(), B.end());
    
    for(int idx = 1 ; idx < A.size() ; idx++){
        if(*s.rbegin()>A[idx]){
            s.erase(s.upper_bound(A[idx]));
            answer++;
        }
    }
    
    return answer;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>a {5,1,3,7};
    vector<int>b {2,2,6,8};
    
    cout<<solution(a, b)<<endl;
    return 0;
}

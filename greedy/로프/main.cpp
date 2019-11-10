//
//  main.cpp
//  2217_lope
//
//  Created by Kim Seong Jin on 2019. 10. 15..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int n){
    vector<int>lopes(n, 0);
    int answer = 0;

    for(int i = 0 ; i < n ; i++)
        cin>>lopes[i];
    sort(lopes.begin(), lopes.end());
    
    for(int i = 0 ; i < lopes.size() ; i++){
        answer = max(answer, (lopes[i] * (n-i)));
    }
    return answer;
    
    
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    cout<<solution(n);
    
    return 0;
}

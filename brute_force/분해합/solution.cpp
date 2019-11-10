//
//  main.cpp
//  2231_분해합
//
//  Created by Kim Seong Jin on 28/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;

int pSum(int n){
    int tmp = n;
    while(tmp>0){
        n+=tmp%10;
        tmp/=10;
    }
    return n;
}

int solution(int n){
    int answer = n;
    int src = n;
    while(src>0){
        int sum = pSum(src);
        if(sum == n){
            answer = min(answer, src);
        }
        src--;
    }
    return answer!=n ? answer : 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int  n;
    cin>>n;
    cout<<solution(n);
    return 0;
}

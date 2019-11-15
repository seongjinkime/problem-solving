//
//  main.cpp
//  2309_일곱난쟁이
//
//  Created by Kim Seong Jin on 31/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int sum;
vector<int>smalles;

void printRes(int current, int walker){
    for(int s : smalles){
        if(s==smalles[current] || s == smalles[walker])
            continue;
        cout<<s<<endl;
    }
}


void getInputs(){
    sum = 0;
    for(int i = 0 ; i < 9 ; i++){
        cin>>smalles[i];
        sum += smalles[i];
    }
}

int main(int argc, const char * argv[]) {
    smalles = vector<int>(9);
    int n = 9;
    getInputs();
    sort(smalles.begin(), smalles.end());
    
    
    for(int current = 0 ; current<n ; current++){
        for(int walker = current+1 ; walker < n ; walker++){
            if(sum-smalles[current]-smalles[walker] == 100){
                printRes(current, walker);
                return 0;
            }
        }
    }
    
    
    return 0;
}

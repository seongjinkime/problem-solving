//
//  main.cpp
//  1983_조교의성적매기기
//
//  Created by Kim Seong Jin on 01/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _STUDENT{
    int id;
    double score;
}student;

vector<student>students;

bool comp(student a, student b){
    return a.score>b.score;
}

void build(int n){
    students = vector<student>(n);
    int mid, fin, assign;
    
    for(int i = 0 ; i < n ; i++){
        cin>>mid>>fin>>assign;
        student s;
        s.id = i+1;
        s.score = (mid*0.35) + (fin*0.45) + (assign*0.2);
        students.push_back(s);
    }

}


void solution(int t, int n, int k){
    string grades[] {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
    build(n);
    int grade = 0;
    int cnt = 0;
    
    sort(students.begin(), students.end(), comp);
    for(int i = 0 ; i < students.size() ; i++){
        if(cnt == n/10){
            grade++;
            cnt = 0;
        }
        cnt++;
        
        if(students[i].id == k){
            printf("#%d %s\n", t, grades[grade].c_str());
            break;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t, n, k;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
        cin>>n>>k;
        solution(i, n,k);
    }
    
     
    return 0;
}

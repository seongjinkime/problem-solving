//
//  main.cpp
//  largestNum
//
//  Created by Kim Seong Jin on 2019. 9. 19..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
int firstDigit(int n){
    while(n>=10) n/=10;
    return n;
}

int getMaxIdx(vector<int>nums){
    int max, fMax, fWalker;
    
    max = 0;
    fMax = firstDigit(nums[max]);
    
    for(int walker = 1 ; walker < nums.size() ; walker++){
        fWalker = firstDigit(nums[walker]);
        if(fWalker > fMax){
            max = walker;
            fMax = firstDigit(nums[max]);
        }
        if(fWalker == fMax){
            if(nums[walker]%10 == 0)
                continue;
            if (nums[walker] > nums[max]){
                max = walker;
                fMax = firstDigit(nums[max]);
            }
        }
    }
    return max;
}

string solution(vector<int> numbers) {
    string answer = "";
    int max;
    while(numbers.size()>0){
        max = getMaxIdx(numbers);
        answer+=to_string(numbers[max]);
        numbers.erase(numbers.begin()+max);
    }
    return answer;
}*/

bool comp(string a, string b){
    if(a.size() == b.size()) return a>b;
    return a+b > b+a;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string>nums;
    
    for(int n : numbers) nums.push_back(to_string(n));
    sort(nums.begin(), nums.end(), comp);
    for(string n : nums) answer+=n;
    
    return answer[0] == '0' ? "0" : answer;
}


int main(void) {
    vector<int> test {0, 0, 0, 100};
    cout << solution(test) <<endl;
    
    
    return 0;
}


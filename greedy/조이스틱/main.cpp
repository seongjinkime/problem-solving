//
//  main.cpp
//  joystick_retry
//
//  Created by Kim Seong Jin on 08/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>
#define MAX 21
using namespace std;

string origin, src;

int up(int idx){
    return origin[idx]-'A';
}
int down(int idx){
    return 'Z'-origin[idx]+1;
}


int solution(string name) {
    int cnt = 0;
    int n = name.size();
    int l,r, gap, current, next;
    origin = name;
    src ="";
    current = 0;
    for(int i = 0 ; i < n ; i++){
        src += "A";
    }
    while(src!=origin){
        gap = 0;
        next = -1;
        
        while(gap<n){
            r = (current+gap)%n;
            l = current - gap;
            if(l<0)
                l += n;
            
            if(name[r]!='A' && src[r]=='A')
                next = r;
            else if(name[l]!='A' && src[l]=='A')
                next = l;
            else{
                gap++;
                continue;
            }
                
            current = next;
            src[current] = name[current];
            
            cnt += gap;
            cnt += min(up(current), down(current));
            break;
        }
    }
    return cnt;
}


int main(int argc, const char * argv[]) {
    cout<<solution("JEROEN")<<endl;
    return 0;
}

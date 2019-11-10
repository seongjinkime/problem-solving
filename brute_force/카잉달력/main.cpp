//
//  main.cpp
//  6604_카잉달력
//
//  Created by Kim Seong Jin on 06/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;



int gcd(int m, int n){
    int a = max(m,n);
    int b = min(m,n);
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int m, int n){
    return m*n/gcd(m,n);
}

void solution(){
    int m,n,x,y;
    
    cin>>m>>n>>x>>y;
    
    int maxYear = lcm(m,n);
    while(true){
        if(x>maxYear || (x)%n == y)
            break;
        x+=m;
    }
    
    if(x>maxYear){
        cout<<-1<<endl;
    }else{
        cout<<x<<endl;
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
        solution();
    }
    //solution();
    //cout<<gcd(20, 10);
    //cout<<lcm(12, 10);
    return 0;
}

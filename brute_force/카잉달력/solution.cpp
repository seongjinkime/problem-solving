//
//  main.cpp
//  6064_카잉달력(retry)
//
//  Created by Kim Seong Jin on 2019. 12. 24..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int a, int b){
    int numA = max(a, b);
    int numB = min(a, b);
    while (numB != 0) {
        int rem = numA % numB;
        numA = numB;
        numB = rem;
    }
    return numA;
}

int lcm(int a, int b){
    return a*b / gcd(a, b);
}

int solve(int m, int n, int x, int y){
    int year, day, limit;
    limit = lcm(m, n);
    year = x%m;
    
    if(year == 0){
        year = m;
    }
    
    while(true){
        day = year % n;
        if(day == 0)
            day = n;
        
        if(day == y)
            return year;
        
        if(year > limit)
            break;
        
        year += m;
    
    }
    return -1;
    
}
int main(int argc, const char * argv[]) {
    int m, n, x, y;
    int t;
    cin>>t;
    
    for(int i = 0 ; i < t ; i++){
        cin>>m>>n>>x>>y;
        cout<<solve(m,n,x,y)<<endl;
    }
    
    return 0;
}

//
//  main.cpp
//  2869_달팽이는올라가고싶다
//
//  Created by Kim Seong Jin on 13/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a,b,v;
    cin>>a>>b>>v;
    int day;
    
    day = (v-a)/(a-b);
    
    if((v-a)%(a-b) != 0)
        day++;
    day+=1;
    cout<<day<<endl;
    return 0;
}

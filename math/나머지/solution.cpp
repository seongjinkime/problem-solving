//
//  main.cpp
//  10403_나머지
//
//  Created by Kim Seong Jin on 26/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a,b,c;
    cin>>a>>b>>c;
    
    cout<<(a+b)%c<<endl;
    cout<<(a%c + b%c)%c<<endl;
    cout<<(a*b)%c<<endl;
    cout<<(a%c * b%c)%c<<endl;
    return 0;
}

//
//  main.cpp
//  10817_세수
//
//  Created by Kim Seong Jin on 2019. 11. 28..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b, c;
    cin>>a>>b>>c;
    int maximum = max(a, max(b, c));
    if(maximum == a){
        cout<<max(b, c)<<endl;
    }else if(maximum == b){
        cout<<max(a, c)<<endl;
    }else if(maximum == c){
        cout<<max(a, b)<<endl;
    }
    return 0;
}

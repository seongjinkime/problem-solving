//
//  main.cpp
//  5086_약수와배수
//
//  Created by Kim Seong Jin on 27/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
using namespace std;

void solve(int a, int b){
    if(b%a == 0){
        cout<<"factor"<<endl;
    }else if (a%b == 0){
        cout<<"multiple"<<endl;
    }else{
        cout<<"neither"<<endl;
    }
}

int main(int argc, const char * argv[]) {
    int a, b;
    
    while(true){
        cin>>a>>b;
        if(a==0 && b == 0)
            break;
        solve(a, b);
    }
    return 0;
}

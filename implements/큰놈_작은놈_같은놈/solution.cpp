//
//  main.cpp
//  2070_큰놈_작은놈_같은놈
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int t, a, b;
    cin>>t;
    
    for(int i = 0 ; i < t; i++){
        cout<<"#"<<i+1<<" ";
        cin>>a>>b;
        if(a>b)
            cout<<">"<<endl;
        else if(a==b)
            cout<<"="<<endl;
        else if(a<b)
            cout<<"<"<<endl;
        
    }
    return 0;
}

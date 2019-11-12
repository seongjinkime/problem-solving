//
//  main.cpp
//  1712_손익분기점
//
//  Created by Kim Seong Jin on 12/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a,b,c;
    cin>>a>>b>>c;
    if(b>=c){
        cout<<-1;
        return 0;
    }
    
    cout<<a/(c-b)+1<<endl;
        
    return 0;
}

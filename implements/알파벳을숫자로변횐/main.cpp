//
//  main.cpp
//  2050_알파벳을숫자로변횐
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    cin>>input;
    for(int i = 0 ; i < input.size() ; i++){
        cout<<input[i]-'A'+1<<" ";
    }
    return 0;
}

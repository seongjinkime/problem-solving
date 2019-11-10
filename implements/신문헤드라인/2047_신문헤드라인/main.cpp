//
//  main.cpp
//  2047_신문헤드라인
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string title;
    cin>>title;
    for(int i = 0 ; i < title.size() ; i++){
        title[i] = toupper(title[i]);
    }
    cout<<title<<endl;
    return 0;
}

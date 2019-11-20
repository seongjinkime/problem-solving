//
//  main.cpp
//  9461_파도반수열
//
//  Created by Kim Seong Jin on 20/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define MAX 101

using namespace std;
typedef long long LL;
LL pado[MAX] = {1, 1, 1};

void init(){
    for(int i = 3 ; i < MAX ; i++){
        pado[i] = pado[i-3] + pado[i-2];
    }
}

int main(int argc, const char * argv[]) {
    init();
    int n, num;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>num;
        cout<<pado[num-1]<<endl;
    }
    return 0;
}

//
//  main.cpp
//  2063_중간값찾기
//
//  Created by Kim Seong Jin on 29/10/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }
    
    sort(arr.begin(), arr.end());
    cout<<arr[n/2]<<endl;
    
    return 0;
}

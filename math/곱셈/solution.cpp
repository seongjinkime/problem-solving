//
//  main.cpp
//  2588_곱셈
//
//  Created by Kim Seong Jin on 26/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b, b1, b2, b3;
    scanf("%d", &a);
    scanf("%1d %1d %1d", &b1, &b2, &b3);
    
    b = b1;
    b = b*10 + b2;
    b = b*10 + b3;
    
    printf("%d\n%d\n%d\n%d\n", a*b3, a*b2, a*b1, a*b);
    
    return 0;
}

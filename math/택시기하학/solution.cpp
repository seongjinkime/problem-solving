//
//  main.cpp
//  3053_택시기하학
//
//  Created by Kim Seong Jin on 25/11/2019.
//  Copyright © 2019 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int r, h, b;
    double uclidArea,taxiArea;
    cin>>r;
    cout<<fixed;
    cout.precision(7);
    
    h = r-(r*-1);
    b = r;
    uclidArea = pow(r, 2) * M_PI;
    taxiArea = abs(h*b);
    
    cout<<uclidArea<<endl<<taxiArea<<endl;
    

    return 0;
}

//
//  main.cpp
//  14500_테트로미노
//
//  Created by Kim Seong Jin on 05/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int table[503][503];
int n, m;


string blocks[19][4] {
        {
            "1111",
            "0000",
            "0000",
            "0000",
        },
        {
            "1000",
            "1000",
            "1000",
            "1000",
        },
        {
            "1100",
            "1100",
            "0000",
            "0000",
        },
        {
            "1000",
            "1000",
            "1100",
            "0000",
        },
        {
            "1110",
            "1000",
            "0000",
            "0000",
        },
        {
            "1100",
            "0100",
            "0100",
            "0000",
        },
        {
            "0010",
            "1110",
            "0000",
            "0000",
        },
        {
            "0100",
            "0100",
            "1100",
            "0000",
        },
        {
            "1000",
            "1110",
            "0000",
            "0000",
        },
        {
            "1100",
            "1000",
            "1000",
            "0000",
        },
        {
            "1110",
            "0010",
            "0000",
            "0000",
        },
        {
            "1000",
            "1100",
            "0100",
            "0000",
        },
        {
            "0110",
            "1100",
            "0000",
            "0000",
        },
        {
            "0100",
            "1100",
            "1000",
            "0000",
        },
        {
            "1100",
            "0110",
            "0000",
            "0000",
        },
        {
            "1110",
            "0100",
            "0000",
            "0000",
        },
        {
            "0100",
            "1100",
            "0100",
            "0000",
        },
        {
            "0100",
            "1110",
            "0000",
            "0000",
        },
        {
            "1000",
            "1100",
            "1000",
            "0000",
        }

};

int getSum(int sy, int sx, int i){
    int sum = 0;
    int ny,nx;
    for(int y = 0 ; y < 4 ; y++){
        ny = sy+y;
        for(int x = 0 ; x < 4 ; x++){
            nx = sx + x;
            sum += (blocks[i][y][x]-'0') * table[ny][nx];
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cin>>table[y][x];
        }
    }
    
    for(int y = n ; y<n+3 ; y++){
        for(int x = 0 ; x < m ; x++){
            table[y][x] = -100000;
        }
    }
    for(int y = 0 ; y < n ; y++){
        for(int x = m ; x < m+3 ; x++){
            table[y][x] = -100000;
        }
    }
    int ret=0;
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x< m ; x++){
            for(int i = 0 ; i < 19 ; i++){
                ret = max(ret, getSum(y, x, i));
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}



/*
 //
 //  main.cpp
 //  14500_테트로미노
 //
 //  Created by Kim Seong Jin on 05/11/2019.
 //  Copyright © 2019 Kim's Inc. All rights reserved.
 //

 #include <iostream>
 #include <vector>

 using namespace std;

 //y, x
 typedef pair<int,int> cr;

 typedef struct _BLOCK{
     cr c1, c2, c3, c4;
     
     _BLOCK(cr _c2, cr _c3, cr _c4 ){
         c1 = cr(0, 0);
         c2 = _c2;
         c3 = _c3;
         c4 = _c4;
     }
     
 }block;
 int n, m;
 vector<vector<int>>table;
 vector<block>blocks;

 void makeBlocks(){
     block nb1(cr(0, 1), cr(0, 2), cr(0,3));
     blocks.push_back(nb1);
     block nb2(cr(1, 0), cr(2, 0), cr(3,0));
     blocks.push_back(nb2);
     block nb3(cr(0, 1), cr(1, 0), cr(1,1));
     blocks.push_back(nb3);
     block nb4(cr(0, 1), cr(-1, 1), cr(-2,1));
     blocks.push_back(nb4);
     block nb5(cr(0, 1), cr(-1, 0), cr(-2,0));
     blocks.push_back(nb5);
     block nb6(cr(0, 1), cr(1, 1), cr(2,1));
     blocks.push_back(nb6);
     block nb7(cr(0, -1), cr(1, -1), cr(2,-1));
     blocks.push_back(nb7);
     block nb8(cr(1, 0), cr(1, 1), cr(2,1));
     blocks.push_back(nb8);
     block nb9(cr(-1, 0), cr(-1, -1), cr(-2,-1));
     blocks.push_back(nb9);
     block nb10(cr(0, -1), cr(1, 0), cr(0, 1));
     blocks.push_back(nb10);
     block nb11(cr(0, -1), cr(-1, 0), cr(0, 1));
     blocks.push_back(nb11);
     
     block nb12(cr(1, 0), cr(1, 1), cr(2, 1));
     blocks.push_back(nb12);
     block nb13(cr(1, 0), cr(1, -1), cr(2, -1));
     blocks.push_back(nb13);
     
     block nb14(cr(0, 1), cr(1, 1), cr(1, 2));
     blocks.push_back(nb14);
     block nb15(cr(0, 1), cr(-1, 1), cr(-1, 2));
     blocks.push_back(nb15);
     
     block nb16(cr(1, 0), cr(1, 1), cr(2, 0));
     blocks.push_back(nb16);
     block nb17(cr(1, 0), cr(-1, 1), cr(2, 0));
     blocks.push_back(nb17);
 }

 void build(){
     table = vector<vector<int>>(n, vector<int>(m));
     for(int i = 0 ; i < n ; i++){
         for(int j = 0 ; j < m ; j++){
             cin>>table[i][j];
         }
     }
 }

 int sum(int y, int x, block b){
     int ret = 0;
     vector<cr> moves {b.c1, b.c2, b.c3, b.c4};
     for(int i = 0 ; i < 4 ; i++){
         int ny = y+moves[i].first;
         int nx = x+moves[i].second;
         if(nx>=0 && nx<m && ny>=0 && ny<n){
             ret += table[ny][nx];
         }
     }
     return ret;
 }

 int maxOfCurrent(int y, int x){
     int ret = 0;
     for(int i = 0 ; i < blocks.size() ; i++){
         ret = max(ret, sum(y, x, blocks[i]));
     }
     
     return ret;
 }

 void solution(){
     build();
     int ret = 0;
     for(int y = 0 ; y < n ; y++){
         for(int x = 0 ; x < m ; x++){
             ret = max(ret, maxOfCurrent(y, x));
         }
     }
     cout<<ret<<endl;
 }

 int main(int argc, const char * argv[]) {
     makeBlocks();
     cin>>n>>m;
     solution();
     
     return 0;
 }

 */

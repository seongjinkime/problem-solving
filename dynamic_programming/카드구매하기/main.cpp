//
//  main.cpp
//  11052_카드구매하기
//
//  Created by Kim Seong Jin on 02/11/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _PACK{
    int num;
    int price;
    double pricePerCard;
    _PACK(int _num, int _price){
        num = _num;
        price = _price;
        pricePerCard = price/num;
    }
}pack;

vector<pack>packs;
int n;

bool comp(pack a, pack b){
    return a.pricePerCard > b.pricePerCard;
}

void buildPack(){
    int price;
    for(int i = 1; i <= n ; i++){
        cin>>price;
        packs.push_back(pack(i, price));
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    buildPack();
    sort(packs.begin(), packs.end(), comp);
    
    int total = 0;
    int idx = 0;
    while(n>0){
        pack p = packs[idx];
        if(n-p.num < 0){
            idx++;
            continue;
        }
        total += p.price;
        n-=p.num;
    }
    cout<<total<<endl;
    
    return 0;
}

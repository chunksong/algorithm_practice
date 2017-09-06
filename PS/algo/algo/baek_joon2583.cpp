//
//  baek_jjon 2583.cpp
//  baek_joon 2583 algo
//  minimum spaning tree
//
//  Created by Hes Song on 9/4/17.
//  Copyright © 2017 Hes Song. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <stack>

typedef struct{
    int row;
    int col;
} point;

int main(int argc, const char * argv[]) {
    
    int row = 0;
    int col = 0;
    int NumOfRactengular = 0;
    
    scanf("%d %d %d", &row, &col, & NumOfRactengular);
    
    std::vector<std::vector<int>> CountryCostGraph(row,std::vector<int>(col,1));
    
    for(int i = 0; i < NumOfRactengular; ++i){
        point p1, p2;
        scanf("%d %d %d %d", &p1.row, &p1.col, &p2.row, &p2.col);
    }
    
    
    for(int i = 0; i < NumOfPath; ++i){
        path pathLen;
        scanf("%d %d %d", &pathLen.startPnt, &pathLen.endPnt, &pathLen.length);
        CountryCostGraph[pathLen.startPnt][pathLen.endPnt] = pathLen.length + CountryCostVec[pathLen.endPnt];
        CountryCostGraph[pathLen.endPnt][pathLen.startPnt] = pathLen.length + CountryCostVec[pathLen.startPnt];
    }
    
    // sort
    ////////////////
    
    
    
    
    return 0;
}

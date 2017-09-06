//
//  baek_joon1185.cpp
//  baek_joon 1185 algo
//  
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
    int startPnt;
    int endPnt;
    int length;
} path;

int main(int argc, const char * argv[]) {
    
    int NumOfCountry = 0;
    int NumOfPath = 0;
    
    int TotalPathLen = 0;
    int CountryCost = 0;
    
    std::vector<std::vector<int>> CountryCostGraph(NumOfCountry+1,std::vector<int>(NumOfCountry+1,0));
    std::vector<int> CountryCostVec;
    std::set<int> checkFlagSet;
    
    CountryCostVec.push_back(0);
    for(int i = 0; i < NumOfCountry; ++i){
        scanf("%d", &CountryCost);
        CountryCostVec.push_back(CountryCost);
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

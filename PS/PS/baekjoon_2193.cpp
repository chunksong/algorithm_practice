//
//  baekjoon_2193.cpp
//  PS
//
//  Created by Hes Song on 8/22/17.
//  Copyright © 2017 Hes Song. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <vector>


int main(int argc, const char * argv[]){
    
    int TestNum;
    scanf("%d",&TestNum);
    
    long long int result = 0;
    //std::vector<long long int> binary;
    std::vector<std::pair<long long int, long long int>> binary;
    
//    binary.push_back(1);
//    binary.push_back(1);
    binary.push_back(std::make_pair(0, 1));
    binary.push_back(std::make_pair(1, 0));
    
//    for(int i = 2; i< TestNum; ++i) binary.push_back(binary[i-2] + binary[i-1]);
    for(int i = 2; i < TestNum; ++i){
        binary.push_back(std::make_pair(binary[i-1].first + binary[i-1].second, binary[i-1].first));
    }

    result = binary[TestNum-1].first + binary[TestNum-1].second;
    printf("%lld\n",result);
    return 0;
}

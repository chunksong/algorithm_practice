//
//  leetcode338_Counting_Bits.cpp
//  DP
//
//  Created by HesSong on 2017. 9. 6..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
    Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    0 1 1 2 1 2 2 3 1 2 2  3  2  3  3  4  1  2  2  3  2
 
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> resultVec;
        int lastSquare = 1;
        for(int i = 0; i <= num ; ++i){
            if(i == 0) resultVec.push_back(0);
            else if(i == lastSquare){
                resultVec.push_back(1);
                lastSquare <<= 1;
            }
            else{
                resultVec.push_back(resultVec[i-(lastSquare/2)]+1);
            }
        }
        return resultVec;
    }
};

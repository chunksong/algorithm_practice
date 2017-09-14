//
//  leetcode70_climbing_stairs.cpp
//  DP
//
//  Created by HesSong on 2017. 9. 13..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    1 2 3 5 8 ...
    
    2 => 1 1, 2
    3 => 1 1 1, 2 1, 1 2
    4 => 1 1 1 1, 2 1 1, 1 2 1, 1 1 2, 2 2
    5 => 1 1 1 1 1, 2 1 1 1, 1 2 1 1, 1 1 2 1, 1 1 1 2, 2 2 1, 2 1 2, 1 2 2
*/

class Solution {
public:
    int climbStairs(int n) {
        
        int result = 0;
        vector<int> cntStair;
        
        for(int i = 0; i < n; ++i){
            if(i < 2)   cntStair.push_back(i+1);
            else{
                cntStair.push_back(cntStair[i-2]+cntStair[i-1]);
            }
        }
        result = cntStair[n-1];
        return result;
    }
};

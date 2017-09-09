//
//  leetcode561_Array_Partition_I.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 8..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 
 Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 
 
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int i = 0; i < nums.size(); i += 2)
            result += nums[i];
        
        return result;
    }
};

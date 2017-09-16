//
//  leetcode485_Max_Consecutive_Ones.cpp
//  array
//
//  Created by HesSong on 2017. 9. 15..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
    Given a binary array, find the maximum number of consecutive 1s in this array.
 
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int count = 0;
        int sizeNum = nums.size();
        bool beforeZero = true;
        for (int i = 0; i < sizeNum; ++i){
            if(nums[i] == 0){
                beforeZero = false;
                result = result < count ? count : result;
                count = 0;
            }
            else{
                count++;
            }
        }
        result = result < count ? count : result;
        return result;
    }
};

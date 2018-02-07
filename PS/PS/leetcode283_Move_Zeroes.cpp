//
//  leetcode283_Move_Zeroes.cpp
//  PS
//
//  Created by HesSong on 2/6/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//
/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 
 For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 
 Note:
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 

 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for(int iter = 0; idx < nums.size(); ++idx){
            if(nums[iter] == 0){
                nums.erase(nums.begin()+iter);
                nums.push_back(0);
                iter -= 1;
            }
            iter += 1;
        }
    }
};

//
//  leetcode1_Two_Sum.cpp
//  Array
//
//  Created by HesSong on 2017. 11. 22..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].

 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int size_input = nums.size();
        
        bool fin_flag = false;
        for(int i = 0; i < size_input; ++i){
            int target_num = target - nums[i];
            for(int j = i + 1; j < size_input; ++j){
                if(nums[j] == target_num){
                    fin_flag = true;
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
            if(fin_flag)    break;
        }
        
        return result;
    }
};

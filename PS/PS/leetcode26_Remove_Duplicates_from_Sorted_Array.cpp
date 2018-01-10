//
//  leetcode26_Remove_Duplicates_from_Sorted_Array.cpp
//  PS
//
//  Created by HesSong on 1/9/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//
/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 0;
        int tmp_num;
        for(int idx = 0; idx < nums.size(); ++idx){
            if(idx == 0){
                tmp_num = nums[idx];
                counter++;
            }
            else{
                if(tmp_num != nums[idx]){
                    tmp_num = nums[idx];
                    nums[counter++] = nums[idx];
                }
            }
        }
        
        return counter;
    }
};

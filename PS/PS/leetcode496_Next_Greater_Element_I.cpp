//
//  leetcode496_Next_Greater_Element_I.cpp
//  PS
//
//  Created by HesSong on 1/27/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//
/*
 You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 
 The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
 
 Example 1:
 Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 Output: [-1,3,-1]
 Explanation:
 For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
 For number 1 in the first array, the next greater number for it in the second array is 3.
 For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 Example 2:
 Input: nums1 = [2,4], nums2 = [1,2,3,4].
 Output: [3,-1]
 Explanation:
 For number 2 in the first array, the next greater number for it in the second array is 3.
 For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 Note:
 All elements in nums1 and nums2 are unique.
 The length of both nums1 and nums2 would not exceed 1000.
 
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        int findNums_size = findNums.size();
        int nums_size = nums.size();
        int next_Val;
        for(int target_idx = 0; target_idx < findNums_size; ++target_idx){
            int target_Num = findNums[target_idx];
            bool flag = false;
            next_Val = -1;
            for(int cursor_idx = 0; cursor_idx < nums_size; ++cursor_idx){
                if(nums[cursor_idx] == target_Num)  flag = true;
                if(flag && nums[cursor_idx] > target_Num){
                    next_Val = nums[cursor_idx];
                    break;
                }
            }
            result.push_back(next_Val);
        }
        return result;
    }
};

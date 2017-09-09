//
//  leetcode442_Find_All_Duplicates_in_an_Array.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 8..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements that appear twice in this array.
 
 Could you do it without extra space and in O(n) runtime?
 
 */
/*
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        vector<int> checkbit(nums.size(),0);
        
        for(int i = 0; i < nums.size(); ++i)    checkbit[nums[i]-1] += 1;
        for(int i = 0; i < checkbit.size(); ++i){
            if(checkbit[i] == 2)    result.push_back(i+1);
        }
        
        return result;
    }
};
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        for(int i = 0; i < nums.size(); ++i){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0) result.push_back(abs(nums[i]));
        }
        
        return result;
    }
};

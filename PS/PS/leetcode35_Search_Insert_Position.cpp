//
//  leetcode35_Search_Insert_Position.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 22..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = 0;
        int numSize = nums.size();
        
        for(int i = 0; i < numSize; ++i){
            if(nums[i] >= target){
                result = i;
                break;
            }
            if(i == numSize - 1)    result = i + 1;
        }
        
        return result;
    }
};

//use O(n) with for iterative, but it can be better when using binary search form.

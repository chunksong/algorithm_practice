//
//  leetcode448_Find_All_Numbers_Disappeared_in_an_Array.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 22..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*

 Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements of [1, n] inclusive that do not appear in this array.
 
 Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 
 Example:
 
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [5,6]

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> result;
        for(int it = 0; it < numSize; ++it){
            nums[abs(nums[it])-1] *= -1;
            if(nums[abs(nums[it])-1] > 0)    result.push_back(numSize-nums[abs(nums[it])-1]);
        }
        
        return  result;
    }
};
// in this case, there are sevral duplicated element in one vector, so it is not a right way to solve it

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> result;
        for(int it = 0; it < numSize; ++it)     nums[abs(nums[it])-1] = -1 * abs(nums[abs(nums[it])-1]);
        for(int it = 0; it < numSize; ++it){
            if(nums[it] > 0)    result.push_back(it + 1);
        }
        
        return  result;
    }
};
// Then just take minus that vector has, after we can find the numbers which vector doesn't have

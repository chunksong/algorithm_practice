//
//  leetcode53_Maximum_subarray.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 21..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*

 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 
 click to show more practice.
 
 More practice:
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int sum = 0;
        int sizeOfVec = nums.size();
        for(int i = 0; i < sizeOfVec; ++i){
            sum += nums[i];
            result = sum < result ? result : sum;
            sum = sum > 0 ? sum : 0;
        }
        return result;
    }
    int maxSubArray_dc(vector<int>& nums,int start, int end){
        int result = num[0];
        int middle = (start + end) / 2;
        //left side & right side
        int leftsideMax = maxSubArray_dc(nums,start,middle);
        int rightsideMax = maxSubArray_dc(nums,middle+1,end);
        //contain middle
        int middleLeft = nums[middle];
        int middleRight = nums[middle+1];
        int temp = 0;
        for(int i = middle; i >= start; i--) {
            temp += nums[i];
            if(temp > middleLeft) middleLeft = temp;
        }
        temp = 0;
        for(int i = middle+1 ; i <= end; i++) {
            temp += nums[i];
            if(temp > middleRight) middleRight = temp;
        }
        return max(max(leftsideMax, rightsideMax), middleLeft+middleRight)
    }
};

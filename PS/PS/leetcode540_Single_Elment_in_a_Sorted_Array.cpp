//
//  leetcode540_Single_Elment_in_a_Sorted_Array.cpp
//  use binary approach
//
//  Created by HesSong on 1/15/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//

/*
 Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.
 
 Example 1:
 Input: [1,1,2,3,3,4,4,8,8]
 Output: 2
 Example 2:
 Input: [3,3,7,7,10,11,11]
 Output: 10
 Note: Your solution should run in O(log n) time and O(1) space.
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sizeOfnums = nums.size();
        return findSingle(nums,0,sizeOfnums-1, sizeOfnums);
    }
    int findSingle(vector<int>& nums, int start, int end, int size){
        if(size == 1) return nums[0];
        else{
            int MidIdx = start + size/2;
            int pivot = nums[MidIdx];
            // cout << size << "pivot : "<< pivot << endl;
            
            if(size == 3){
                int result = (nums[start] != pivot)? nums[start]: nums[end];
                return result;
            }
            if(nums[MidIdx + 1] == pivot){        //same value in rightside
                // cout << "right" << endl;
                if((end - (MidIdx + 2) + 1)%2 == 1)  return findSingle(nums,MidIdx + 2, end, end-(MidIdx + 2)+1);
                else                                  return findSingle(nums,start,MidIdx - 1, (MidIdx - 1) - start + 1);
            }
            else if(nums[MidIdx - 1] == pivot){   //same value in leftside
                // cout << "left" << endl;
                if(((MidIdx - 2) - start + 1)%2 == 1)  return findSingle(nums,start,MidIdx - 2, (MidIdx - 2) - start + 1);
                else                                  return findSingle(nums,MidIdx + 1, end, end -(MidIdx + 1) + 1);
                
            }
            else return pivot;
        }
    }
};

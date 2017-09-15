//
//  leetcode553_Optimal_Division.cpp
//  String
//
//  Created by HesSong on 2017. 9. 14..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 
 Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.
 
 However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.
 
 Note:
 
 The length of the input array is [1, 10].
 Elements in the given array will be in range [2, 1000].
 There is only one optimal division for each test case.
 
 */

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string result;
        if(nums.size() < 3){
            for(int i = 0 ; i < nums.size(); ++i){
                if(i == 0) result += to_string(nums[i]);
                else result += ("/" + to_string(nums[i]));
            }
        }
        else{
            for(int i = 0 ; i < nums.size(); ++i){
                if(i == 0){
                    result += to_string(nums[i]);
                    result += "/(";
                }
                else if(i == nums.size() -1)    result += to_string(nums[i]) + ')';
                else    result += (to_string(nums[i]) + "/");
            }
        }
        return result;
    }
};

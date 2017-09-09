//
//  leetcode566_Reshape_the_Matrix.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 8..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
 
 You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
 
 The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
 
 If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
 
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        if(nums.size() * nums[0].size() < r * c)    return nums;
        else{
            vector<vector<int>> result(r,vector<int>(c,0));
            
            int row_n = 0;
            int col_n = 0;
            for(int row = 0; row < r; ++row){
                for(int col = 0; col < c; ++col){
                    if(col_n >= nums[0].size()){
                        col_n = 0;
                        row_n += 1;
                    }
                    result[row][col] = nums[row_n][col_n];
                    col_n += 1;
                }
            }
            return result;
        }
    }
};

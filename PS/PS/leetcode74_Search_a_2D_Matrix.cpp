//
//  leetcode74_Search_a_2D_Matrix.cpp
//  Just look these like 1D array don't care about dimension
//
//  Created by HesSong on 1/25/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//
/*
 
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,
 
 Consider the following matrix:
 
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 Given target = 3, return true.
 
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row_max = matrix.size();
        if(matrix[0].empty())       return false;
        int col_max = matrix[0].size();
        int start = 0, end = row_max * col_max - 1;
        
        if(matrix[0][0] > target || matrix[row_max-1][col_max-1] < target)    return false;
        
        int mid,midRow,midCol;
        
        while(start <= end)
        {
            mid = (start+end)/2;
            midCol = mid%col_max;
            midRow = mid/col_max;
            if(matrix[midRow][midCol] < target)
                start = mid+1;
            else if(matrix[midRow][midCol] > target)
                end = mid-1;
            else
                return true;
        }
        return false;
        
        
    }
    
};

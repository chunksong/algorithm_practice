//
//  leetcode413_Arithmetic_Slices.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 21..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 
 For example, these are arithmetic sequence:
 
 1, 3, 5, 7, 9
 7, 7, 7, 7
 3, -1, -5, -9
 The following sequence is not arithmetic.
 
 1, 1, 2, 5, 7
 
 A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 
 A slice (P, Q) of array A is called arithmetic if the sequence:
 A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
 
 The function should return the number of arithmetic slices in the array A.
 
 
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        int ASize = A.size();
        vector<int> differenceVec;
        
        if(ASize <  3)      return 0;
        for(int i = 0; i < ASize - 1; ++i){
            int difference = A[i + 1] - A[i];
            differenceVec.push_back(difference);
        }
        int diffVecSize = differenceVec.size();
        vector<int> sameDiffCntVec;
        int Count = 1;
        int diff = differenceVec[0];
        for(int i = 1; i < diffVecSize; ++i){
            if(diff != differenceVec[i]){
                sameDiffCntVec.push_back(Count);
                Count = 1;
                diff = differenceVec[i];
            }
            else    ++Count;
        }
        sameDiffCntVec.push_back(Count);
        
        for(int i = 0; i < sameDiffCntVec.size(); ++i)   result += (sameDiffCntVec[i] * (sameDiffCntVec[i] - 1) / 2);
        
        return result;
    }
};

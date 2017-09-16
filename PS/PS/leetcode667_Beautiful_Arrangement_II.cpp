//
//  leetcode667_Beautiful_Arrangement_II.cpp
//  Array
//
//  Created by HesSong on 2017. 9. 15..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 
 Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
 Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
 
 If there are multiple answers, print any of them.
 
 */

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int l = 1, r = k+1;
        vector<int> result;
        while (l <= r) {
            result.push_back(l++);
            if (l <= r) result.push_back(r--);
        }
        for (int i = k+2; i <= n; i++)
            result.push_back(i);
        return result;
    }
};

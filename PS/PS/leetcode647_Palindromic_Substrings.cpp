//
//  leetcode647_Palindromic_Substrings.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 13..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 Given a string, your task is to count how many palindromic substrings in this string.
 
 The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 
 
 NEED TO STUDY MORE ABOUT IT
 */

class Solution {
    public:
    int countSubstrings(string s) {
        int result = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)result++; //substring s[i-j, ..., i+j]
            for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)result++; //substring s[i-1-j, ..., i+j]
        }
        
        return result;
    }
};

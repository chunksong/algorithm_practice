//
//  leetcode557_Reverse_Words_in_a_String_III.cpp
//  String
//
//  Created by HesSong on 2017. 9. 14..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 
 */
class Solution {
public:
    string reverseWords(string s) {
        string result;
        int startIndex = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' '){
                for(int j = i-1; j >= startIndex; --j)   result += s[j];
                result += " ";
                startIndex = i+1;
            }
        }
        for(int j = s.length() - 1; j >= startIndex; --j)   result += s[j];
        return result;
    }
};

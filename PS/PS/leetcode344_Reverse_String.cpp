//
//  leetcode344_Reverse_String.cpp
//  String
//
//  Created by HesSong on 2017. 9. 21..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 
 Write a function that takes a string as input and returns the string reversed.
 
 Example:
 Given s = "hello", return "olleh".
 
 */

class Solution {
public:
    string reverseString(string s) {
        string result;
        for(int i = s.size() - 1;i >= 0; --i)    result += s[i];
        return result;
    }
};

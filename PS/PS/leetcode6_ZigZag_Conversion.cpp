//
//  leetcode6_ZigZag_Conversion.cpp
//  PS
//
//  Created by HesSong on 2018. 1. 2..
//  Copyright © 2018년 Hes Song. All rights reserved.
//
/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int strLen = s.length();
        
        vector<string> note(numRows,"");
        
        if(numRows == 1)    return s;                                   // reason of runtime error
        
        bool downFlag = true;
        int strIdx = 0;
        for(int i = 0; i < strLen; ++i){
            note[strIdx] += s[i];
            
            if(downFlag)    strIdx++;
            else            strIdx--;
            if(strIdx == 0) downFlag = true;
            else if(strIdx == numRows - 1)  downFlag = false;           // if "numRows" case wasn't treated, this part can be problem
        }
        
        for(int idx = 0; idx < numRows; ++idx){
            result += note[idx];
        }
        
        return result;
    }
}; 

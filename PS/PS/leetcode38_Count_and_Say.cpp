//
//  leetcode38_Count_and_Say.cpp
//  PS
//
//  Created by HesSong on 1/11/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//
/*
 The count-and-say sequence is the sequence of integers with the first five terms as following:
 
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth term of the count-and-say sequence.
 
 Note: Each term of the sequence of integers will be represented as a string.
 
 Example 1:
 
 Input: 1
 Output: "1"
 Example 2:
 
 Input: 4
 Output: "1211"
 
 */
class Solution {
public:
    string countAndSay(int n) {
        string result="1";
        if(n == 0) return "";
        for(int i = 2; i <= n; ++i){
            char currChar = result[0];
            string tmp = "";
            int cnt = 0;
            for(int cursor = 0; cursor < result.length(); ++cursor){
                if(result[cursor] != currChar){
                    tmp += to_string(cnt) + currChar;
                    currChar = result[cursor];
                    cnt = 1;
                }
                else    cnt++;
            }
            tmp += to_string(cnt) + currChar;
            result = tmp;
        }
        return result;
    }
};


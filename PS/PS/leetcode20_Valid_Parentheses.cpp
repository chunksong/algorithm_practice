//
//  leetcode20_Valid_Parentheses.cpp
//  PS
//
//  Created by HesSong on 2018. 1. 5..
//  Copyright © 2018년 Hes Song. All rights reserved.
//
/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 
 */
class Solution {
public:
    bool isValid(string s) {
        bool result;
        stack<int> stack_s;
        int sLen = s.length();
        
        //( { [ 에 맞는 닫는 괄호가 나오면 pop  끝까지 같는데 스택이 안비면 false
        for(int cursor = 0; cursor < sLen; cursor++){
            if(s[cursor] == '(')    stack_s.push(1);
            else if(s[cursor] == '{')   stack_s.push(2);
            else if(s[cursor] == '[')   stack_s.push(3);
            else if(s[cursor] == ')' && !stack_s.empty() && stack_s.top() == 1) stack_s.pop();
            else if(s[cursor] == '}' && !stack_s.empty() && stack_s.top() == 2) stack_s.pop();
            else if(s[cursor] == ']' && !stack_s.empty() && stack_s.top() == 3) stack_s.pop();
            else    return false;
        }
        if(stack_s.empty()) result = true;
        else        result = false;
        
        return result;
    }
};

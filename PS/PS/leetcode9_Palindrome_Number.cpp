//
//  leetcode9_Palindrome_Number.cpp
//  PS
//
//  Created by HesSong on 2018. 1. 3..
//  Copyright © 2018년 Hes Song. All rights reserved.
//
/*
 Determine whether an integer is a palindrome. Do this without extra space.
 
 click to show spoilers.
 
 Some hints:
 Could negative integers be palindromes? (ie, -1)
 
 If you are thinking of converting the integer to string, note the restriction of using extra space.
 
 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 
 There is a more generic way of solving this problem.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        int num = x;
        int a = 0;
        while(x){
            a = a*10 + x%10;
            x = x/10;
        }
        
        if(a == num)
            return true;
        else
            return false;
        
    }
};

//
//  leetcode202_Happy_Number.cpp
//  PS
//
//  Created by HesSong on 2/16/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//
/*
 Write an algorithm to determine if a number is "happy".
 
 A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 
 Example: 19 is a happy number
 
 1^2 + 9^2 = 82
 8^2 + 2^2 = 68
 6^2 + 8^2 = 100
 1^2 + 0^2 + 0^2 = 1
 
 */
class Solution {
public:
    bool isHappy(int n) {
        int target = n;
        int next_num = 0;
        while(target != 0){
            next_num += (target % 10)*(target % 10);
            target /= 10;
            if(next_num == 1 && target == 0)    return true;
            else if(target == 0){
                if(next_num < 7)    return false;
                target = next_num;
                next_num = 0;
            }
        }
        return false;
    }
};

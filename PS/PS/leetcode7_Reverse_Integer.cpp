//
//  leetcode7_Reverse_Integer.cpp
//  string으로 접근시 예외 처리 발생 직접 해결
//  Created by HesSong on 2018. 1. 1..
//  Copyright © 2018년 Hes Song. All rights reserved.
//
/*
 Given a 32-bit signed integer, reverse digits of an integer.
 
 Example 1:
 
 Input: 123
 Output:  321
 Example 2:
 
 Input: -123
 Output: -321
 Example 3:
 
 Input: 120
 Output: 21
 Note:
 Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        //         bool minus_flag = false;
        
        //         if(x < 0){
        //             minus_flag = true;
        //             x *= -1;
        //         }
        //         string temp = to_string(x);
        //         int len_num = temp.length();
        
        //         string answer = "";
        
        //         for(int iter = len_num - 1; iter >= 0; --iter){
        
        //             answer += temp[iter];
        //         }
        //         cout << answer<< endl;
        //         result = stof(answer);
        //         cout << result;
        
        //         if(result >= 2147483648) result = 0;
        //         else if(minus_flag) result *= -1;
        
        while(x != 0){
            result = result*10 + x%10 ;
            x /= 10;
            if (result >= 2147483648 || result <= -2147483648)  return 0;
        }
        
        return (int)result;
    }
};

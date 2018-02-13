//
//  leetcode89_Gray_Code.cpp
//  PS
//
//  Created by HesSong on 2/12/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//

/*
 The gray code is a binary numeral system where two successive values differ in only one bit.
 
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 Note:
 For a given n, a gray code sequence is not uniquely defined.
 
 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 
 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        vector<int> tmp;
        if(n == 0)  result.push_back(0);
        tmp.push_back(0);
        for(int i = 0; i < n; ++i){
            vector<int> res;
            for(int sub_i = 0; sub_i < (1<<i); ++ sub_i){
                if (sub_i % 2 == 0){
                    res.push_back(tmp[sub_i]*2 + 0);
                    res.push_back(tmp[sub_i]*2 + 1);
                }
                else{
                    res.push_back(tmp[sub_i]*2 + 1);
                    res.push_back(tmp[sub_i]*2 + 0);
                }
            }
            tmp = res;
            result = res;
        }
        return result;
    }
};

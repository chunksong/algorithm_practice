//
//  leetcode537_Complex_Number_Multiplication.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 7..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 Given two strings representing two complex numbers.
 
 You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
 
 */
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        
        string integer_f = a.substr(0,a.find('+'));
        string complex_f = a.substr(a.find('+')+1, a.size()-1);
        string integer_s = b.substr(0,b.find('+'));
        string complex_s = b.substr(b.find('+')+1, b.size()-1);
        
        int int_f = convert(integer_f);
        int int_s = convert(integer_s);
        
        int comp_f = convert(complex_f);
        int comp_s = convert(complex_s);
        
        int int_res = 0;
        int comp_res = 0;
        
        int_res = int_f * int_s - comp_f * comp_s;
        comp_res = int_f * comp_s + int_s * comp_f;
        string result = "";
        
        result += to_string(int_res) + "+" + to_string(comp_res) + "i";
        
        return result;
    }
    int convert(string numstr){
        int num = 0;
        
        if(numstr.find('-') != string::npos){
            num = stoi(numstr.substr(1,numstr.size()));
            num *= -1;
        }
        else    num = stoi(numstr);
        return num;
    }
};

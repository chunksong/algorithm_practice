//
//  leetcode339_Evaluate_Division.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 22..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*

 Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
 
 Example:
 Given a / b = 2.0, b / c = 3.0.
 queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 return [6.0, 0.5, -1.0, 1.0, -1.0 ].
 
 The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
 
 According to the example above:
 
 equations = [ ["a", "b"], ["b", "c"] ],
 values = [2.0, 3.0],
 queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
 The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

*/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> result;
        
        //act like pair -- share index;
        vector<string> alphaStr;
        vector<double> alphaVal;
        
        //vector<pair<string,double>> alpha;
        
        ///////////////////need to modi 이부분에서 처음것이 아니더라도 두개 모두 새로나온것이면 갱신을 해줄 필요성이 있음. 따라서 첫번째 나오는 값은 1로 저장하지만 else 문 이후 시행에서는 원래 값을 바꿔줄 필요가 있어보임
        for(int i = 0; i < equations.size(); ++i){
            //pair<string, double> temp_f, temp_s;
            string temp_f_str, temp_s_str;
            double temp_f_val, temp_s_val;
            if(i == 0){
                //temp_f.first = equations[i].first;
                //temp_f.second = 1;
                temp_f_str = equations[i].first;
                temp_f_val = 1;
                
                //temp_s.first = equations[i].second;
                //temp_s.second = 1 / values[0];
                temp_s_str = equations[i].second;
                temp_s_val = 1 / values[i];
                
                //alpha.push_back(temp_f);
                //alpha.push_back(temp_s);
                alphaStr.push_back(temp_f_str);
                alphaVal.push_back(temp_f_val);
                alphaStr.push_back(temp_s_str);
                alphaVal.push_back(temp_s_val);
                
            }
            else{
                auto pos_f = find(alphaStr.begin(), alphaStr.end(), equations[i].first);
                auto pos_s = find(alphaStr.begin(), alphaStr.end(), equations[i].second);
                if(pos_f == alphaStr.end() && pos_s == alphaStr.end()){
                    
                }
                else if(pos_f == alphaStr.end()){
                    temp_f_str = equations[i].first;
                    temp_f_val = alphaVal[distance(alphaStr.begin(), pos_s)] * values[i];
                    alphaStr.push_back(temp_f_str);
                    alphaVal.push_back(temp_f_val);
                }
                else if(pos_s == alphaStr.end()){
                    temp_s_str = equations[i].second;
                    temp_s_val = alphaVal[distance(alphaStr.begin(), pos_f)] / values[i];
                    alphaStr.push_back(temp_s_str);
                    alphaVal.push_back(temp_s_val);
                }
                else{
                    ;//all of them is new value
                }
            }
        }
        
        
        for(int i = 0; i < queries.size(); ++i){
            auto pos_f = find(alphaStr.begin(), alphaStr.end(), queries[i].first);
            auto pos_s = find(alphaStr.begin(), alphaStr.end(), queries[i].second);
            
            if(pos_f != alphaStr.end() && pos_s != alphaStr.end() ){
                result.push_back(alphaVal[distance(alphaStr.begin(), pos_f)] / alphaVal[distance(alphaStr.begin(), pos_s)]);
            }
            else    result.push_back(-1);
        }
        
        return result;
    }
};

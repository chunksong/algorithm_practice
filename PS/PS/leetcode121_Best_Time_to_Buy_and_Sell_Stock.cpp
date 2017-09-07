//
//  leetcode121_Best_Time_to_Buy_and_Sell_Stock.cpp
//  DP
//
//  Created by HesSong on 2017. 9. 6..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 
 
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minimumPrice;
        for(int i = 0; i < prices.size(); ++i){
            if(i == 0) minimumPrice = prices[i];
            else{
                if(minimumPrice > prices[i])    minimumPrice = prices[i];
                else maxProfit = maxProfit > (prices[i] - minimumPrice) ? maxProfit : (prices[i] - minimumPrice);
            }
        }
        return maxProfit;
    }
};

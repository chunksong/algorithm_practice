//
//  leetcode11_Container_With_Most_Water.cpp
//  use two cursors for finding out max value.
//
//  Created by HesSong on 2018. 1. 5..
//  Copyright © 2018년 Hes Song. All rights reserved.
//
/*
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container and n is at least 2.
 
 */


class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int vecSize = height.size();
        int first = 0, second = vecSize - 1;
        
        int heightValStart = height[first] * 1 < height[second] * 1 ? height[first] * 1 : height[second] * 1;
        result = heightValStart * (second - first);
        while(first < vecSize && second < vecSize && first >= 0 && second >= 0 && first < second){
            int midHeightVal = height[first] < height[second] ? height[first] : height[second];
            int midVolVal = midHeightVal * (second - first);
            result = result < midVolVal ? midVolVal : result;
            
            if(height[first] < height[second])                first++;
            else if(height[second] < height[first])            second--;
            else{
                second--;
                first++;
            }
            
        }
        
        
        return result;
    }
};

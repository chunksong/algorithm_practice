//
//  leetcode539_Minimum_Time_difference.cpp
//  solve string problem using 2d vector
//
//  Created by HesSong on 2017. 10. 10..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        auto numberOfTP = timePoints.size();
        int result = 20000;
        
        vector<vector<int>> timePnt(49,vector<int>(60,0));
        
        for(auto iter = 0; iter < numberOfTP; ++iter){
            auto timePntIdx = stoi(timePoints[iter].substr(0,2));
            auto timePntMin = stoi(timePoints[iter].substr(3,5));
            timePnt[timePntIdx][timePntMin] += 1;
            timePnt[24+timePntIdx][timePntMin] += 1;
        }
        
        int lastHour = -10000;
        int lastMin = -10000;
        int differenceHour = 0;
        int differenceMin = 0;
        for(auto iter = 0; iter < 48; ++iter){
            for(auto min_it = 0; min_it < 60; ++min_it){
                if (timePnt[iter][min_it] > 1){
                    cout << iter << ":" << min_it << " - " << lastHour << ":" << lastMin << endl;
                    result = 0;
                    break;
                }
                else if(timePnt[iter][min_it] == 1){
                    // cout << iter << ":" << min_it << " - " << lastHour << ":" << lastMin << endl;
                    differenceHour = iter - lastHour;
                    lastHour = iter;
                    differenceMin = min_it - lastMin;
                    lastMin = min_it;
                    // cout << abs(60 * differenceHour + differenceMin) << endl;
                    result = result < abs(60 * differenceHour + differenceMin) ? result : abs(60 * differenceHour + differenceMin);
                }
                
            }
        }
        
        return result;
    }
};

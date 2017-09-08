//
//  leetcode657_Judge_Route_Circle.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 7..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 
 The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 
 
 */
class Solution {
public:
    bool judgeCircle(string moves) {
        int vCnt = 0; //vertical count
        int hCnt = 0; //horizental count
        for(int i = 0 ; i < moves.size(); ++i){
            if(moves[i] == 'U')     ++vCnt;
            else if(moves[i] == 'D')    --vCnt;
            else if(moves[i] == 'L')    --hCnt;
            else if(moves[i] == 'R')    ++hCnt;
        }
        
        if(vCnt == 0 && hCnt ==0)   return true;
        else    return false;
    }
};

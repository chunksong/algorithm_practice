//
//  baekjoon_9465.cpp
//  DP 
//
//  Created by Hes Song on 8/21/17.
//  Copyright © 2017 Hes Song. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <functional>

int main(int argc, const char * argv[]){
    
    int TestCaseNum;
    scanf("%d",&TestCaseNum);
    
    for(int i = 0; i< TestCaseNum; ++i){
        
        int result = 0;
        int columnNum = 0;
        scanf("%d", &columnNum);
        
        std::vector<std::vector<int>> board;
        std::vector<std::vector<int>> result_board;
        for(int i = 0 ; i < 2 ; ++i){
            std::vector<int> row;
            std::vector<int> result_row(columnNum,0);
            for(int column = 0; column < columnNum; ++column){
                int input_num = 0;
                scanf("%d", &input_num);
                row.push_back(input_num);
            }
            result_board.push_back(result_row);
            board.push_back(row);
        }
        //board setup
        result_board[0][0] = board[0][0];
        result_board[1][0] = board[1][0];
        result_board[0][1] = board[0][1] + board[1][0];
        result_board[1][1] = board[1][1] + board[0][0];
        
        
        for(int i = 2 ; i < columnNum; ++i){
            result_board[0][i] = board[0][i] + result_board[1][i-1] > board[0][i] + result_board[1][i-2] ? board[0][i] + result_board[1][i-1] : board[0][i] + result_board[1][i-2];
            result_board[1][i] = board[1][i] + result_board[0][i-1] > board[1][i] + result_board[0][i-2] ? board[1][i] + result_board[0][i-1] : board[1][i] + result_board[0][i-2];
        }
        
        for(int iCursor = columnNum-1; iCursor > columnNum - 3; --iCursor){
            result = result_board[0][iCursor] > result ? result_board[0][iCursor] : result;
            result = result_board[1][iCursor] > result ? result_board[1][iCursor] : result;
        }
        
        printf("%d\n",result);
    }
    
    return 0;
}

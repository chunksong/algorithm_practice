//
//  leetcode515_Find_Largest_Value_in_Each_Tree_Row.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 26..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*

 You need to find the largest value in each row of a binary tree.
 
 Example:
 Input:
 
 1
 / \
 3   2
 / \   \
 5   3   9
 
 Output: [1, 3, 9]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        int depth = countDepth(root);
        if(depth == 0){
            vector<int> nullVec;
            return nullVec;
        }
        vector<int> result(depth, -1);
        calMaxOfLevels(root,0,result);
        return result;
    }
    int countDepth(TreeNode* root){
        int subDepth = 0;
        if(root == NULL)   return 0;
        
        int leftSub = countDepth(root->left);
        int rightSub = countDepth(root->right);
        subDepth = leftSub > rightSub ? leftSub : rightSub;
        return subDepth + 1;
    }
    void calMaxOfLevels(TreeNode* root, int depth, vector<int> &maxVec){
        if(maxVec[depth] == -1) maxVec[depth] = root->val;
        else maxVec[depth] = maxVec[depth] < root->val ? root->val : maxVec[depth];
        
        if(root->left != NULL)  calMaxOfLevels(root->left, depth + 1, maxVec);
        if(root->right != NULL) calMaxOfLevels(root->right, depth + 1, maxVec);
    }
    
};

//
//  leetcode513_Find_Bottom_Left_Tree_Value.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 20..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 
 Given a binary tree, find the leftmost value in the last row of the tree.
 
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
    void findBottomLeftValue(TreeNode* root, int& maxDepth, int& leftVal, int depth) {
        if (root == NULL) {
            return;
        }
        //Go to the left and right of each node
        findBottomLeftValue(root->left, maxDepth, leftVal, depth+1);
        findBottomLeftValue(root->right, maxDepth, leftVal, depth+1);
        
        //Update leftVal and maxDepth
        if (depth > maxDepth) {
            maxDepth = depth;
            leftVal = root->val;
        }
    }
    
    //Entry function
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        //Initialize leftVal with root's value to cover the edge case with single node
        int leftVal = root->val;
        findBottomLeftValue(root, maxDepth, leftVal, 0);
        return leftVal;
    }
};

//
//  leetcode647_Average_of_Levels_in_Binary_Tree.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 26..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 
 Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
 
 Example 1:
 Input:
 3
 / \
 9  20
 /  \
 15   7
 Output: [3, 14.5, 11]
 Explanation:
 The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
 Note:
 The range of node's value is in the range of 32-bit signed integer.
 
 
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
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        
        int totalDepth = countDepth(root);
        
        vector<double> sumOfLevels(totalDepth,0);
        vector<int> cntOfLevels(totalDepth,0);
        
        calSumOfLevels(root, 0, sumOfLevels, cntOfLevels);
        
        for(auto i = 0; i < totalDepth; ++i){
            result.push_back(sumOfLevels[i]/cntOfLevels[i]);
        }
        
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
    
    void calSumOfLevels(TreeNode* root, int depth, vector<double> &sumVec, vector<int> &cntVec){
        
        sumVec[depth] += root->val;
        cntVec[depth] += 1;
        
        if(root->left != NULL)  calSumOfLevels(root->left, depth + 1, sumVec, cntVec);
        if(root->right != NULL) calSumOfLevels(root->right, depth + 1, sumVec, cntVec);
    }
};

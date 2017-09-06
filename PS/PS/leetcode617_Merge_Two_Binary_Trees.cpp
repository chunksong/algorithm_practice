//
//  leetcode617_Merge_Two_Binary_Trees.cpp
//  PS
//
//  Created by Hes Song on 9/5/17.
//  Copyright © 2017 Hes Song. All rights reserved.
//

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* newTree = new TreeNode(0);
        if(t1 != NULL && t2 != NULL){
            if(t1->left == NULL && t2->left == NULL)    newTree->left = NULL;
            else if(t1->left == NULL)    newTree->left = t2->left;
            else if(t2->left == NULL)    newTree->left = t1->left;
            else newTree->left = mergeTrees(t1->left,t2->left);
            
            if(t1->right == NULL && t2->right == NULL)    newTree->right = NULL;
            else if(t1->right == NULL)   newTree->right = t2->right;
            else if(t2->right == NULL)   newTree->right = t1->right;
            else newTree->right = mergeTrees(t1->right, t2->right);
            
            newTree->val = t1->val + t2->val;
            return newTree;
        }
        else if(t1 != NULL){
            newTree->left = t1->left;
            newTree->right = t1 -> right;
            newTree->val = t1->val;
            return newTree;
        }
        else if(t2 != NULL){
            newTree->left = t2->left;
            newTree->right = t2 -> right;
            newTree->val = t2->val;
            return newTree;
        }
        else return NULL;
    }
};

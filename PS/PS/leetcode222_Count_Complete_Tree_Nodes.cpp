//
//  leetcode222_Count_Complete_Tree_Nodes.cpp
//  PS
//
//  Created by HesSong on 2/13/18.
//  Copyright © 2018 Hes Song. All rights reserved.
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

/*
 Given a complete binary tree, count the number of nodes.
 
 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 

 
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        TreeNode* currentNode_l = root;
        TreeNode* currentNode_r = root;
        
        int sub_l = 0;
        int sub_r = 0;
        while(currentNode_l->left != NULL){
            sub_l++;
            currentNode_l = currentNode_l->left;
        }
        while(currentNode_r->right != NULL){
            sub_r++;
            currentNode_r = currentNode_r->right;
        }
        
        if(sub_l == sub_r && sub_r != 0)            return (1 << sub_r+1) -1;
        else                 return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};

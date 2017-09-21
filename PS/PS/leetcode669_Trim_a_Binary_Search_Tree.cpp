//
//  leetcode669_Trim_a_Binary_Search_Tree.cpp
//  PS
//
//  Created by HesSong on 2017. 9. 20..
//  Copyright © 2017년 Hes Song. All rights reserved.
//

/*
 
 Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
 
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode *currentNode = root;
        
        if(root == NULL)    return NULL;
        else{
            currentNode->left = trimBST(currentNode->left,L,R);
            currentNode->right = trimBST(currentNode->right,L,R);
            
            if(currentNode->val < L || currentNode->val > R){
                if(currentNode->left != NULL && currentNode->right != NULL){
                    currentNode->val = currentNode->left->val;
                    
                    TreeNode *tempNode = currentNode->right;
                    while(tempNode->left != NULL)   tempNode = tempNode->left;
                    tempNode->left = currentNode->left->right;
                    
                    currentNode = currentNode->left;
                }
                else if(currentNode->left != NULL)  currentNode = currentNode->left;
                else if(currentNode->right != NULL)   currentNode = currentNode->right;
                else    currentNode = NULL;
            }
            
            return currentNode;
        }
        
    }
};

//
//  leetcode654_maximum_binary_tree.cpp
//  PS
//
//  Created by Hes Song on 8/29/17.
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if(nums.size() == 0) return NULL;
        
        struct TreeNode* max_tree;
        max_tree = new struct TreeNode(nums[0]);
        int root_idx = 0;
        vector<int> left_sub;
        vector<int> right_sub;
        int v_size = nums.size();
        max_tree->val = nums[0];
        
        if(v_size == 1)    return max_tree;
        
        for(int i = 0; i < v_size; ++i){
            if (nums[i] > max_tree->val){
                max_tree->val = nums[i];
                root_idx = i;
            }
        }
        for(int i = 0; i < v_size; ++i){
            if (i < root_idx)       left_sub.push_back(nums[i]);
            else if(i > root_idx)   right_sub.push_back(nums[i]);
        }
        
        max_tree->left = constructMaximumBinaryTree(left_sub);
        max_tree->right = constructMaximumBinaryTree(right_sub);
        
        return max_tree;
    }
};

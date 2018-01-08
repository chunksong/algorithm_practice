//
//  leetcode21_Merge_Two_Sorted_list.cpp
//  continusly adding problem in Linked List
//
//  Created by HesSong on 2018. 1. 7..
//  Copyright © 2018년 Hes Song. All rights reserved.
//
/*
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 Example:
 
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* result = NULL;
        ListNode* cursor_re;
        bool startFlag = false;
        
        while(l1 != NULL && l2 != NULL){
            ListNode* newNode;
            if(!startFlag){
                if(l1->val > l2->val){
                    newNode = new ListNode(l2->val);
                    l2 = l2->next;
                }
                else{
                    newNode = new ListNode(l1->val);
                    l1 = l1->next;
                }
                result = newNode;
                cursor_re = result;
                startFlag = true;
            }
            else{
                if(l1->val > l2->val){
                    newNode = new ListNode(l2->val);
                    l2 = l2->next;
                }
                else{
                    newNode = new ListNode(l1->val);
                    l1 = l1->next;
                }
                cursor_re->next = newNode;
                cursor_re = newNode;
            }
        }
        while(l1 != NULL){
            ListNode* newNode = new ListNode(l1->val);
            if(!startFlag){
                result = newNode;
                cursor_re = result;
                startFlag = true;
            }
            else{
                cursor_re->next = newNode;
                cursor_re = newNode;
            }
            l1 = l1->next;
            
        }
        while(l2 != NULL){
            ListNode* newNode = new ListNode(l2->val);
            if(!startFlag){
                result = newNode;
                cursor_re = result;
                startFlag = true;
            }
            else{
                cursor_re->next = newNode;
                cursor_re = newNode;
            }
            l2 = l2->next;
            
        }
        return result;
    }
};

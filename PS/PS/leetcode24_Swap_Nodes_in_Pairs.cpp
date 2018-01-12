//
//  leetcode24_Swap_Nodes_in_Pairs.cpp
//  PS
//
//  Created by HesSong on 1/11/18.
//  Copyright © 2018 Hes Song. All rights reserved.
//
/*
 Given a linked list, swap every two adjacent nodes and return its head.
 
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 
 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 2->1->3->4
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int idx = 0;
        ListNode* cursorNode = head;
        while(cursorNode != NULL){
            ListNode* preNode;
            ListNode* prePreNode;
            ListNode* nextNode;
            
            nextNode = cursorNode->next;
            if(idx%2 == 1){
                if(idx == 1) head = cursorNode;
                else prePreNode->next=cursorNode;
                preNode->next = cursorNode->next;
                cursorNode->next = preNode;
            }
            else{
                if(idx != 0) prePreNode = preNode;
                preNode = cursorNode;
            }
            
            cursorNode = nextNode;
            idx++;
        }
        return head;
    }
};

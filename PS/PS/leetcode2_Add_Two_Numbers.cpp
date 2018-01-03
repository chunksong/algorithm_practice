//
//  leetcode2_Add_Two_Numbers.cpp
//  Linked list
//
//  Created by HesSong on 2017. 11. 22..
//  Copyright © 2017년 Hes Song. All rights reserved.
//
/*
 
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode* fastNode = new ListNode(0);
        
        result = fastNode;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            ListNode* currentNode = new ListNode(0);
            fastNode->next = currentNode;
            if(l1 == NULL && l2 ==NULL){
                currentNode->val = carry;
                carry = 0;
            }
            else if(l1 == NULL){
                currentNode->val = l2->val;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                currentNode->val = l1->val;
                l1 = l1->next;
            }
            else{
                currentNode->val = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            currentNode->val = carry + currentNode->val;
            if(currentNode->val >= 10){
                currentNode->val -= 10;
                carry = 1;
            }
            else    carry = 0;
            fastNode = currentNode;
        }
        
        result = result->next;
        return result;
    }
};

/*
 @ July 10 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 2. Add Two Numbers
* 
    You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8

*/
	 



/**
use loop to scan each digits in two numbers.
there are several condition should be conserned:
1. one of lists is empty---->directly return the other one
2. if the addition of two digits is bigger than 10---> value -= 10, and there is a flag to store whether there are carries.
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
        ListNode *newhead;
        if(l1 ==NULL) return l2;
        else if(l2 ==NULL) return l1;
        int flag =0; //flag ==flase means result of adding two val is smaller than 10.
        int headval = l1->val + l2->val;
        if(headval >=10){
            headval -= 10;
            flag = 1;
        }
        else flag =0;
        newhead = new ListNode(headval);
        newhead->next = NULL;
        ListNode *root = newhead;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL && l2 != NULL){
            int value = l1->val + l2->val + flag;
            if(value >= 10){
                value -= 10;
                flag = 1;
            }
            else flag =0;
            
            ListNode *node = new ListNode(value);
            node -> next = NULL;
            root->next = node;
            root = root->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            int value = l1->val + flag;
            if(value >=10){
                value -= 10;
                flag =1;
            }
            else flag = 0;
            ListNode *node = new ListNode(value);
            node->next = NULL;
            root->next = node;
            root = root->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int value = l2->val + flag;
            if(value >=10){
                value -= 10;
                flag =1;
            }
            else flag = 0;
            ListNode *node = new ListNode(value);
            node->next = NULL;
            root->next = node;
            root = root->next;
            l2 = l2->next;
        }
        
        if(flag == 1){
            ListNode *node = new ListNode(1);
            node->next = NULL;
            root->next = node;
        }
        return newhead;
        
    }
};
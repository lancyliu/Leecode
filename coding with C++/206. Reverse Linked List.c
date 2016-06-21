/*
 @ Jun 21 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 206. Reverse Linked List
* 
   Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
		
		//build a new list node to store the new linked list.
        ListNode *newhead = new ListNode(head->val); 
        newhead -> next = NULL;
        
		//store the reverse linked list.
        while(head != NULL)
        {
            head = head -> next;
            if(head != NULL){
            ListNode *temp = new ListNode(head->val);
            temp-> next = newhead;
            newhead = temp;
         }
         else break;  
		}
		
        return newhead;
    }
};
/*
 @ July 1 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 19. Remove Nth Node From End of List
* 
   Given a linked list, remove the nth node from the end of list and return its head.

   For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
   
   Note:
     Given n will always be valid.
     Try to do this in one pass.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *root = head;
        int number = 0;

        while(root != NULL){
            number++;
            root = root->next;
        }
        if(n==number) return head->next;
        
        int i=1;
        root = head;
        while(i< number - n){
            root = root ->next;
            i++;
        }
        
        if(n>1){
            ListNode *temp = root->next->next;
            root->next = temp;
        }
        else root->next = NULL;
        return head;
    }
};
/*
 @ July 1 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 21. Merge Two Sorted Lists
* 
   Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
        ListNode *head;
        if(l1 ==NULL) return l2;
        else if(l2 ==NULL) return l1;
        if(l1 -> val <= l2 -> val) {
            head = l1;
            l1 = l1->next;
            if(l1 == NULL){
                head -> next = l2;
                return head;
            }
        }
        else {
            head = l2;
            l2 = l2->next;
            if(l2 == NULL){
                head -> next = l1;
                return head;
            }
        }
        
        ListNode *current = head;
        while(l1 != NULL){
            while(l2 != NULL){
                if(l1 -> val <= l2 -> val) {
                    current -> next = l1;
                    current = current->next;
                    break;
                }
                else{
                    current -> next = l2;
                    current = current->next;
                    l2 = l2 -> next;
                }
            }
            if(l2 == NULL) break;
            else l1 = l1 -> next;
        }
        if(l1 != NULL) current ->next = l1;
        else if(l2 != NULL) current ->next = l2;
        return head;
    }
};
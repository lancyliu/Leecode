/*
 @ July 1 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 83. Remove Duplicates from Sorted List
* 
  Given a sorted linked list, delete all duplicates such that each element appear only once.

  For example,
     Given 1->1->2, return 1->2.
     Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = head;
        if(head == NULL) return head;
        while(root->next != NULL){
        
            if(root->val == root->next->val){
                ListNode *temp = root->next->next;
                root->next = temp;
            }
            else{
                root = root->next;
            }
        }
        return head;
    }
};
/*
 @ July 8 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 237. Delete Node in a Linked List
* 
    Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

    Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
	the linked list should become 1 -> 2 -> 4 after calling your function.

*/
	 



/**
just pass the val of the node, then delete the tail node.
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
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next==NULL) return;
        else{
            while(node ->next->next != NULL){
                node -> val = node->next->val;
                node = node->next;
            }
            node ->val = node->next->val;
            node->next = NULL;
            return;
        }
        
    }
};
/*
 @ July 8 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 24. Swap Nodes in Pairs
* 
    Given a linked list, swap every two adjacent nodes and return its head.

    For example,
      Given 1->2->3->4, you should return the list as 2->1->4->3.

      Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/
	 



/**
draw a picture and make it clear about next, root and the connection.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        else{
            ListNode *root = head;
            ListNode *temp = root->next;
            root->next = root->next->next;
            temp->next = root;
            head = temp;
            //root = root->next;
            
            while(root != NULL && root->next != NULL && root->next->next !=NULL){
                ListNode *temp = root->next;
                root->next = root->next->next;
                root = root->next;
                temp->next = root->next;
                 root->next = temp;
                root = root->next;
            }
            return head;
        }
    }
};
/*
 @ July 7 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 234. Palindrome Linked List
* 
   Given a singly linked list, determine if it is a palindrome.

   Follow up:
     Could you do it in O(n) time and O(1) space?

*/
	 



/**
add a newhead which start from the tail of the linked list. while head starts from the beginning of the linked list.
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
		ListNode* newhead = new ListNode(head->val);
        newhead ->next = NULL;
        ListNode *copy =head;
        //cout<<"test sign1"<<endl;
        int size =1;
		while(copy->next != NULL){
           
			ListNode *temp = new ListNode(copy->next->val);
           
            temp -> next = newhead;
          
            newhead = temp;
            
            copy = copy->next;
            //cout<<size<<endl;
            ++size;
        }
        //cout<<"size"<<size<<endl;
        int m=1;
        while(m<= size/2){
            ListNode *forward = head;
            ListNode *backward = newhead;
            if(forward->val != backward->val) return false;
            else {
                ++m;
                head = head ->next;
                newhead = newhead->next;
            }
        }
        return true;
    }
};
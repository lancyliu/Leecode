/*
 @ Jun 22 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 203. Remove Linked List Elements
* 
   Remove all elements from a linked list of integers that have value val.

  Example
   Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
   Return: 1 --> 2 --> 3 --> 4 --> 5

*/
	 


/*
  
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
    ListNode* removeElements(ListNode* head, int val) {
      if(head == NULL) return NULL;
        
		//find the right head position.
        while(head != NULL)
		{
			if(head -> val == val) head = head -> next;
			else break;
		}
        if( head == NULL) return NULL;
        ListNode *current = head;  //for now, head -> val != val.
		while(current->next != NULL)
        {
            if(current ->next -> val != val)
            {
				//if this val != val, we can skip this node to the next node.
                current = current -> next;
            }
            else
            {
				//if this val == val, we should delete it. there are two condition: 
				//1. the next -> next is not null,
				if(current -> next ->next != NULL) 
				{
					ListNode *temp = current -> next -> next;
					current -> next = temp;
					//do not need this sentence, cause we delete current -> next, and now we have a new current -> next to consider.
                   // current = current -> next; 
				}
				else 
				{
					//2. next -> next is null, thus we scan all nodes, break.
					current -> next = NULL;
					break;
				}
                
            }
        }
        
        return head;
    }
};
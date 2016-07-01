/*
 @ Jun 27 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 141. Linked List Cycle
* 
   Given a linked list, determine if it has a cycle in it.

   Follow up:
     an you solve it without using extra space?

*/
	 



class Solution {
public:
    bool hasCycle(ListNode *head) {
     //method1: time exceed.
     /*
      vector<ListNode*> nodes;
      while(head != NULL){
          if(!nodes.empty()){
              for(unsigned i=0; i<nodes.size(); i++){
              if(nodes.at(i) == head) return true;
              else 
			  {
				  nodes.push_back(head);
				  break;
			  }
          }
          }
          else nodes.push_back(head);
          
          head = head -> next;
      }
      return false;
      */
      
      //method2: use two pointer: slow and faster.
      // the idea came from http://www.cnblogs.com/yrbbest/p/4438817.html
      if(head == NULL || head -> next == NULL) return false;
      ListNode *slow = head;
      ListNode *faster = head;
      while(faster != NULL && faster->next != NULL){
          slow = slow -> next;
          faster = faster -> next -> next;
          if(slow == faster) return true;
      }
      return false;
    }
};
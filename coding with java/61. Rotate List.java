/*
 @ July 24 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  61. Rotate List
* 
    Given a list, rotate the list to the right by k places, where k is non-negative.

    For example:
     Given 1->2->3->4->5->NULL and k = 2,
     return 4->5->1->2->3->NULL.


*/
	 

/**

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(k <= 0) return head;
        if(head == null) return head;
        
        int number =1;
        ListNode tail = head;
        while(tail.next != null){
            number++;
            tail = tail.next;
        }
      
        
        if(number == 1) return head;
        while(k >= number) k= k-number;
        if(k==0) return head;
        
        int index = number - k;
        int count = 1;
        ListNode copy = head;
       
        while(count < index){
            copy = copy.next;
            count++;
        }
        
        ListNode newhead = copy.next;
        copy.next = null;
        tail.next = head;
      
        return newhead;
    }
}
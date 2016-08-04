/*
 @ Aug 2 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  82. Remove Duplicates from Sorted List II
* 
    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

    For example,
    Given 1->2->3->3->4->4->5, return 1->2->5.
    Given 1->1->1->2->3, return 2->3.


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
    public ListNode deleteDuplicates(ListNode head) {
        //remove duplicates from head.
        if(head == null || head.next == null) return head;
        while(head !=null && head.next != null){
            if(head.val == head.next.val){
                ListNode temp = head.next;
                while(temp.next != null){
                    if(temp.val == temp.next.val){
                        temp = temp.next;
                    }
                    else break;
                }
                head = temp.next;
            }
            else break;
        }
        if(head == null) return head;
        //now head is not duplicates. remove duplicates behind head;
        ListNode current = head;
        while(current.next != null && current.next.next != null){
            if(current.next.next.val == current.next.val){
                ListNode temp = current.next.next;
                while(temp.next != null){
                    if(temp.val == temp.next.val) temp = temp.next;
                    else break;
                }
                current.next = temp.next;
            }
            else current = current.next;
        }
        return head;
    }
}
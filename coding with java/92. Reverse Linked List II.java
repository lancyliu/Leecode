/*
 @ Aug 4 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  92. Reverse Linked List II
* 
    Reverse a linked list from position m to n. Do it in-place and in one-pass.

    For example:
     Given 1->2->3->4->5->NULL, m = 2 and n = 4,

     return 1->4->3->2->5->NULL.

   Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.



*/
	 

/**
use an array to store the values between m--n. then change the values in list.
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        int[] values = new int [n-m+1];
        if(head == null || head.next == null) return head;
        if(m == n) return head;
        ListNode current = head;
        int count = 1;
        while(count <m && current != null){
            current = current.next;
            count++;
        }
        ListNode record = current;
        while(count <= n && record != null){
            values[count-m] = record.val;
            record = record.next;
            count++;
        }
        int it = m;
        while(it <= n){
            current.val = values[values.length-it+m-1];
            current = current.next;
            it++;
        }
        return head;
    }
}
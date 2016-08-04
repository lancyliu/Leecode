/*
 @ Aug 1 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  86. Partition List
* 
    Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the two partitions.

    For example,
     Given 1->4->3->2->5->2 and x = 3,
     return 1->2->2->4->3->5.


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
    public ListNode partition(ListNode head, int x) {
        //get tail of this list
        if(head == null || head.next ==null) return head;
        ListNode tail = head;
        int count =1;
        while(tail.next != null){
            count++;
            tail = tail.next;
        }
        System.out.println(count);
        int i=1;
        while(head != null && head.val >= x && i<= count){
            tail.next = head;
            tail = tail.next;
            head = head.next;
            tail.next = null;
            i+=1;
            System.out.println("check one " + i);
        }
        ListNode current = head; 
        if(i == count && current.val < x) return head;
        while(current != null && current.next != null && i < count){
              if(current.next.val >= x){
                tail.next = current.next;
                tail = tail.next;
                current.next = current.next.next;
                
                tail.next = null;
                i+=1;
                System.out.println("i "+ i + "value "+ current.val);
            }
            else {
                current = current.next;
                i++;
                System.out.println("another i "+ i + "value "+ current.val);
            }
        }
        return head;
    }
}
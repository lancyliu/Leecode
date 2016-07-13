/*
 @ July 12 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 2. Add Two Numbers
* 
    You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8

*/
	 



/**
use loop to scan each digits in two numbers.
there are several condition should be conserned:
1. one of lists is empty---->directly return the other one
2. if the addition of two digits is bigger than 10---> value -= 10, and there is a flag to store whether there are carries.
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null)return l2;
        else if(l2 == null) return l1;
        ListNode newhead;
        int flag = 0;
        int value = l1.val + l2.val;
        
        if(value >= 10){
            value -= 10;
            flag = 1;
        }
        newhead = new ListNode(value);
        newhead.next = null;
        
        ListNode curnode = newhead;
        l1 = l1.next;
        l2 = l2.next;
        while(l1 != null & l2 != null){
            int v = l1.val + l2.val+flag;
            if(v>= 10){
                v -= 10;
                flag = 1;
            }
            else flag =0;
            ListNode newnode = new ListNode(v);
            newnode.next = null;
            curnode.next = newnode;
            curnode = curnode.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        System.out.println(flag);
        while(l1 != null){
            int v = l1.val + flag;
            if(v >=10){
                v -= 10;
                flag = 1;
                ListNode newnode = new ListNode(v);
                newnode.next = null;
                curnode.next = newnode;
                curnode = curnode.next;
                l1 = l1.next;
            }
            else {
                flag =0;
                ListNode newnode = new ListNode(v);
                newnode.next = l1.next;
                curnode.next = newnode;
                curnode = curnode.next;
                break;
            }
        }
        
        while(l2 != null){
            int v = l2.val + flag;
            if(v >=10){
                v -= 10;
                flag =1;
                ListNode newnode = new ListNode(v);
                newnode.next = null;
                curnode.next = newnode;
                curnode = curnode.next;
                l2 = l2.next;
            }
            else{
                flag =0;
                ListNode newnode = new ListNode(v);
                newnode.next = l2.next;
                curnode.next = newnode;
                curnode = curnode.next;
                break;
            }
        }
        
        if(flag ==1){
            ListNode newnode = new ListNode(1);
            newnode.next = null;
            curnode.next = newnode;
        }
        return newhead;
    }
}
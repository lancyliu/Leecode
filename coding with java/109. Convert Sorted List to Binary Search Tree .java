/*
@ Feb 13 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 109. Convert Sorted List to Binary Search Tree
*
 Given a singly linked list where elements are sorted in ascending order, 
 convert it to a height balanced BST.
* 
*/


/*in each iteration store the value it should be, and node/direction in the next iteration*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        //method 1: store linked list to an array, then contruct the tree.
        //method 2: use two pointer(slow & faster), this idea was learned from discussion section.
        if(head ==null) return null;
        if(head.next == null) return new TreeNode(head.val);
        ListNode tail = null;
        return getTree(head, tail);
        
    }
    
    public TreeNode getTree(ListNode head, ListNode tail){
        ListNode slow = head;
        ListNode faster = head;
        
        if(tail == head) return null;
        
        while(faster != tail &&  faster.next !=tail){
            faster = faster.next.next;
            slow = slow.next;
        }
        //the tail's value is not considered to use, thus left tree we can use slow.
        TreeNode root = new TreeNode(slow.val);
        root.left = getTree(head,slow);
        root.right = getTree(slow.next, tail);
        return root;
    }
}
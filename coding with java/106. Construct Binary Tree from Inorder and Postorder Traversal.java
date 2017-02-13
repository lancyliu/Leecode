/*
@ Feb 13 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 106. Construct Binary Tree from Inorder and Postorder Traversal
*
  Given inorder and postorder traversal of a tree, construct the binary tree.

  Note:
   You may assume that duplicates do not exist in the tree.
* 
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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder.length == 0) return null;
        
        return getTree(inorder,postorder,0, inorder.length-1, 0, postorder.length-1);
    }
    
    public TreeNode getTree(int[] inorder, int[] postorder, int infrom, int into, int pfrom,int pto){
        if(pfrom > pto) return null;
        if(infrom >= inorder.length) return null;
        int index = infrom;
        TreeNode root = new TreeNode(postorder[pto]);
        for(int i=infrom; i<=into; i++){
            if(inorder[i] == postorder[pto]){
                 index = i;
                 break;
            }
        }
        root.left = getTree(inorder,postorder,infrom, index-1, pfrom, pfrom + index-infrom-1);
        root.right = getTree(inorder,postorder, index+1, into, pfrom+ index-infrom, pto-1);
        return root;
    }
}
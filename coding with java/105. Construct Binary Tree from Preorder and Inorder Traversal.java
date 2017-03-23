/*
@ Feb 13 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 105. Construct Binary Tree from Preorder and Inorder Traversal
*
 Given preorder and inorder traversal of a tree, construct the binary tree.

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        //in preorder, value in index 0 is the root.val
        //TreeNode result = new TreeNode;
        if(preorder.length == 0) return null;
        
        TreeNode root = new TreeNode(preorder[0]);
        int start =0;
        int end = preorder.length;
        
        return getTree(preorder,inorder,0,preorder.length-1, start,end-1);
    }
    
    public TreeNode getTree(int[] preorder, int[] inorder,int pstart, int pend, int start, int end){
        System.out.println(start + "  " + end);
        TreeNode root;
        if(pstart >= preorder.length) return null;
        else root = new TreeNode(preorder[pstart]);
        int value = preorder[pstart];
        int index=start;
        if(pend < pstart) return null;
        for(int i=start; i<=end; i++){
            if(inorder[i] == value){
                index = i;
                break;
            }
        }
        root.left = getTree(preorder, inorder, pstart+1, pstart + index-start, start,index-1);
        root.right = getTree(preorder,inorder, pstart + index-start +1,pend, index+1, end);
        /*
        //get index of root in inorder array, then left part is inorder result of left tree
        if(index <= start){//left tree is null
             root.left = null;
             start += 1;
             System.out.println("check 1");
             root.right = getTree(preorder,inorder,pstart+1,pstart + index-start, start,end);
        }
        else if(index == start +1){
            //only one node in left side. add this node to root.left
            TreeNode temp = new TreeNode(inorder[start]);
            start += 2;
            root.left = temp;
            System.out.println("check 2");
            //pre should be added the distance between start and index + 1.
            root.right = getTree(preorder,inorder,pre+2,start,end);
        }
        else{
            System.out.println("check 3");
            // for left part change the end number, for right part change the start number
            int end1 = index-1;
            int start2 = index+1;
            int pre1 = pre + 1;
            if(pre1 < preorder.length)  root.left = getTree(preorder,inorder,pre1,start,end1);
            else root.left = null;
            int pre2 = pre + index-start +1;
            if(pre2 < preorder.length) root.right = getTree(preorder,inorder,pre2,start2,end);
            else root.right = null;
        }
        */
        return root;
        
    }
}
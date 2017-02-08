/*
@ Feb 8 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 94. Binary Tree Inorder Traversal
*
   Given a binary tree, return the inorder traversal of its nodes' values.

   For example:
   Given binary tree [1,null,2,3],
      1
       \
        2
       /
      3
   return [1,3,2].


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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        
        //中序遍历
        /*using recursive*/
        /*
        TreeNode curNode = root;
        recur_Traversal(result, curNode);
        return result;
        */
        /*using iterate*/
        Stack<TreeNode> s = new Stack<TreeNode>();
        //if this node contains left child, put it to the stack, if not, pop it, turn to it right child.
        TreeNode curNode = root;

        s.push(curNode);
        while(!s.empty()){
            curNode = s.peek();
            while(curNode.left != null){
                curNode = curNode.left;
                System.out.println("test point 1");
                //if(curNode == null) break;
                s.push(curNode);
                //else break;
            }
            if(!s.empty()){
                curNode = s.pop();
                result.add(new Integer(curNode.val));
                if(curNode.right !=null) s.push(curNode.right);
            }
            
             
        }
        return result;
    }

    /*
    public void recur_Traversal(List<Integer> result, TreeNode curNode){
            if(curNode == null) return;
            if(curNode.left != null) recur_Traversal(result, curNode.left);
            result.add(new Integer(curNode.val));
            if(curNode.right != null) recur_Traversal(result,curNode.right);
    }
    */

}
/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 114. Flatten Binary Tree to Linked List
*
 Given a binary tree, flatten it to a linked list in-place.

 For example,
 Given
 
          1
         / \
        2   5
       / \   \
      3   4   6
 The flattened tree should look like:
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
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
    public void flatten(TreeNode root) {
        //preoder of tree
        if(root == null) return;
        if(root.left ==null & root.right ==null) return;
        List<Integer> result = new ArrayList<Integer>();
        getTraversal(root,result);
        getNewTree(root,result);
    }
    
    public void getTraversal(TreeNode root,List<Integer> result){
        //pre traversal
        if(root == null) return;
        result.add(root.val);
        if(root.left != null) getTraversal(root.left,result);
        if(root.right !=null) getTraversal(root.right,result);
    }
    
    public void getNewTree(TreeNode root, List<Integer> result){
        for(int i=1; i<result.size(); i++){
            root.right = new TreeNode(result.get(i));
            root.left = null;
            root = root.right;
        }
    }
}
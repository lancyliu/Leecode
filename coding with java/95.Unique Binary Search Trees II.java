/*
@ Feb 8 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 95. Unique Binary Search Trees II
*
   Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

   For example,
   Given n = 3, your program should return all 5 unique BST's shown below.

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3
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
    public List<TreeNode> generateTrees(int n) {
       int start = 1;
       int end = n;
       if(n==0) return new ArrayList<TreeNode>();
        
       return getTree(start,end);
    }
    /*use divide and conqure to solve this problem*/
    public List<TreeNode> getTree(int start, int end){
        List<TreeNode> result = new ArrayList<TreeNode>();
        if(start > end){
            result.add(null); 
            return result;
        }
        for(int i=start; i<=end; i++){
            //get all left tree 
            List<TreeNode> leftTree = getTree(start, i-1);
            //get all right tree
            List<TreeNode> rightTree = getTree(i+1, end);
            
            //this node is new root node, add all combination of left&right sub-tree to build a new tree
            for(int m=0; m < leftTree.size(); m++){
                for(int n=0; n< rightTree.size(); n++){
                    TreeNode temp = new TreeNode(i);
                    temp.left = leftTree.get(m);
                    temp.right = rightTree.get(n);
                    result.add(temp);
                }
            }
        }
        return result;
    }
}
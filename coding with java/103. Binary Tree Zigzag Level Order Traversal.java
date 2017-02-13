/*
@ Feb 13 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 103. Binary Tree Zigzag Level Order Traversal
*
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

 For example:
   Given binary tree [3,9,20,null,null,15,7],
       3
      / \
     9  20
       /  \
      15   7
   return its zigzag level order traversal as:
   [
     [3],
     [20,9],
     [15,7]
   ]
* 
*/


/*in each iteration store the value it should be, and node/direction in the next iteration*/

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<TreeNode> nodeList = new ArrayList<TreeNode>();
        nodeList.add(root);
        if(root == null) return result;
        int direction = 1;
        
        while(!nodeList.isEmpty()){
            List<Integer> temp = new ArrayList<Integer>();
            List<TreeNode> nodes = new ArrayList<TreeNode>();
            if(direction ==1){
                for(int i=0; i<nodeList.size();i++){
                    if(nodeList.get(i) != null) temp.add(nodeList.get(i).val);
                }
            }
            else{
                for(int i=nodeList.size()-1;i>=0;i--){
                   if(nodeList.get(i) != null) temp.add(nodeList.get(i).val); 
                }
            }
            for(int i=0; i<nodeList.size(); i++){
                //if(nodeList.get(i) !=null) temp.add(nodeList.get(i).val);
                if(nodeList.get(i).left != null) nodes.add(nodeList.get(i).left);
                if(nodeList.get(i).right != null) nodes.add(nodeList.get(i).right);
            }
            result.add(temp);
            nodeList = nodes;
            direction *= (-1);
        }
        
        return result;
    }
}
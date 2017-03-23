/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 113. Path Sum II
*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 For example:
   Given the below binary tree and sum = 22,
                 5
                / \
               4   8
              /   / \
             11  13  4
            /  \    / \
           7    2  5   1
   return
   [
      [5,4,11,2],
      [5,8,4,5]
   ]
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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        int score = 0;
        if(root == null) return result;
        List<Integer> temp = new ArrayList<Integer>();
        getSum(result,root,sum,score,temp);
        return result;
    }
    
    public void getSum(List<List<Integer>> result, TreeNode node, int sum, int score,List<Integer> temp){
        //if this node is a leaf node.
        if(node.left ==null && node.right ==null && (score+node.val) ==sum) {
            temp.add(node.val);
            result.add(temp);
            return;
        }
        else if(node.left ==null && node.right ==null) return;
        //else if(sum >=0 && (score+node.val) >= sum) return;//if node is not leaf node,but score is not valid.
        else{
            //node is not leaf node and score is now valid.
            temp.add(node.val);
            score += node.val;
            List<Integer> t1 = new ArrayList<Integer>(temp);
            List<Integer> t2 = new ArrayList<Integer>(temp);
            if(node.left != null) getSum(result,node.left,sum,score,t1);
            if(node.right !=null) getSum(result,node.right,sum,score,t2);
        }
        return;
        
        
    }
}
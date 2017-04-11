/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 129. Sum Root to Leaf Numbers
*
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    public int sumNumbers(TreeNode root) {
        ArrayList<Integer> num = new ArrayList<Integer>();
        int result;
        result = dfs(root, num);
        return result;
    }
    
    public int dfs(TreeNode root, ArrayList<Integer> num){
        //System.out.println("test " + result);
        int result = 0;
        if(root == null) return 0;
        else if(root.left == null && root.right == null){
            num.add(root.val);
            result += getNum(num);
            //System.out.println(result);
            num.remove(num.size()-1);
            //num.clear();
            return result;
        }
        num.add(root.val);
        if(root.left != null){
            //num.add(root.val);
            result = result + dfs(root.left, new ArrayList<Integer>(num));
        }
        
        if(root.right != null){
            //num.add(root.val);
            result =  result + dfs(root.right, new ArrayList<Integer>(num));
        }
        return result;
    }
    
    public int getNum(ArrayList<Integer> num){
        int result = 0;
        for(int i=0; i<num.size(); i++){
            result += num.get(i) * Math.pow(10, (num.size()-1-i));
        }
        //System.out.println(result);
        return result;
    }
}
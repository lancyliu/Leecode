/*
 @ Jun 30 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 112. Path Sum
* 
   Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

   For example:
   Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
   return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/
	 



/**
use dfs.
*/	 
	 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
       return dfs(root,sum);
    }
    
	/**
	sum stores the value of current path sum.
	everytime we pass a node, we minus the value of this node in sum.
	only when we reaches the leaf node and the sum is equals the value of the leaf node, the function will return true.
	*/
    bool dfs(TreeNode *root, int sum){
        if(root == NULL) return false;
        
        TreeNode *left = root -> left;
        TreeNode *right = root -> right;
        if(left != NULL && right == NULL) return dfs(left,sum- root->val);
        else if(left == NULL && right != NULL) return dfs(right, sum - root->val);
        else if(left ==NULL && right ==NULL && sum==root->val) return true;
        else if(left == NULL && right ==NULL && sum!=root->val)return false;
        else return (dfs(left,sum- root->val) || dfs(right, sum - root->val));
    }
};
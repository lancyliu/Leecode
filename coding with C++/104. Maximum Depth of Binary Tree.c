/*
 @ Jun 30 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 104. Maximum Depth of Binary Tree
* 
   Given a binary tree, find its maximum depth.

   The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/
	 


/*use depth first search to search the tree.*/

	 
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
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
    
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        else{
        
          TreeNode *left = root -> left;
          TreeNode *right = root -> right;
        
          if(right == NULL && left == NULL) return 1;
          else if(right != NULL && left != NULL){
              int dl = dfs(left);
              int dr = dfs(right);
            
              if(dl <= dr) return dr +1;
              else return dl +1;
           }
           else if(right ==NULL && left != NULL){
               return dfs(left) +1;
           }
           else return dfs(right) +1;
        }
    }
};
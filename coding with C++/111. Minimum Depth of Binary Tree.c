/*
 @ Jun 30 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 111. Minimum Depth of Binary Tree
* 
   Given a binary tree, find its minimum depth.

   The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.



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
    int minDepth(TreeNode* root) {
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
            
              if(dl <= dr) return dl +1;
              else return dr +1;
           }
           else if(right ==NULL && left != NULL){
               return dfs(left) +1;
           }
           else return dfs(right) +1;
        }
    }
};
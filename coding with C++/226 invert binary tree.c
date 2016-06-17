/*
 @ May 30 2016 Monday
 @ by Xin Liu 
*/

/**Description of the problem**/
/* LeetCode 226. Invert Binary Tree
* 
   Invert a binary tree.
      
          4
        /   \
       2     7
      / \   / \
     1   3 6   9
   to
          4
        /   \
       7     2
      / \   / \
     9   6 3   1

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
    TreeNode* invertTree(TreeNode* root) {
		
        if(root == NULL) return NULL;
        TreeNode *temp;
        temp = root -> left;
        root -> left = invertTree(root -> right);;
        root -> right = invertTree(temp); 
        return root;
         
    }
};
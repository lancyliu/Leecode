/*
 @ Jun 30 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 101. Symmetric Tree
* 
   Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

   For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

         1
        / \
       2   2
      / \ / \
     3  4 4  3
   But the following [1,2,2,null,3,null,3] is not:
        1
       / \
      2   2
       \   \
       3    3

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        TreeNode *left = root -> left;
        TreeNode *right = root -> right;

		/**
		if left node and right node both null, the result will be true;
		if one of it is null, result will be false
		if both are not null, and have the same value, the following work we call function dfs(left,right);
		*/
        if(left==NULL && right==NULL) return true;
        else if(left!=NULL && right!=NULL){
           if(left->val == right->val) return bfs(left,right);
           else return false;
        } 
        else return false;
    }
    
	/**
	To check whether the tree is Symmetric, then the left->left should equal to right->right, left->right should equal to right->left.
	if all these four are null, result true
	if one pair of these is null, check the not-null pair.
	if all these four are not null, check both.
	other condition will result false.
	*/
    bool bfs(TreeNode *left, TreeNode *right){
		
        if(left->left ==NULL && right -> right==NULL && left->right==NULL && right->left==NULL) return true;
        else if(left->left ==NULL && right -> right==NULL && left->right!=NULL && right->left!=NULL ){
            if(left->right->val == right->left->val) return bfs(left->right,right->left);
            else return false;
        } 
        else if(left->left !=NULL && right -> right!=NULL && left->right==NULL && right->left==NULL){
            if(left->left->val == right->right->val) return bfs(left->left,right->right);
            else return false;
        }
        
        else if(left->left!=NULL && left->right != NULL && right->left!= NULL && right->right != NULL){
            if(left->left->val == right->right->val && left->right->val == right->left->val)
              return bfs(left->left, right->right) && bfs(left->right, right->left);
            else return false;
            
        }
        else return false;
        
    }
};
/*
 @ Jun 30 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 110. Balanced Binary Tree
* 
   Given a binary tree, determine if it is height-balanced.

  For this problem, a height-balanced binary tree is defined as a binary tree 
  in which the depth of the two subtrees of every node never differ by more than 1.



*/
	 


/**
add a new function to find the maximum depth of the tree/subtree.
if this node only have left or right child node, 
   we can check if left/right child node also have children, then we should return false, since the differences is already bigger than 1.
   else if left/right child node do not have any children, we should return true, since the subtree whose root is node is balanced.
if this node have both left and right child node.
  at first,we check the maximum depth of left subtree and right subtree,
    if the differences is bigger than 1, we can return false.
	else, we  recursively check if both left and right subtree is balanced.
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        else if(root ->left == NULL && root ->right != NULL){
            if(root->right->left!=NULL || root->right->right!=NULL) return false;
            else return true;
        }
        else if(root ->left != NULL && root -> right ==NULL){
            if(root->left->left != NULL || root->left->right != NULL) return false;
            else return true;
        }
        else{
            
            int lmax = dfsMax(root -> left);
            int rmax = dfsMax(root->right);
            
            if(lmax - rmax <=1 && lmax-rmax >=-1){
                return isBalanced(root->left) &&isBalanced(root->right);
            } 
            else return false;
        }
       
    }
    
    int dfsMax(TreeNode* root){
        if(root == NULL) return 0;
        else{
        
          TreeNode *left = root -> left;
          TreeNode *right = root -> right;
        
          if(right == NULL && left == NULL) return 1;
          else if(right != NULL && left != NULL){
              int dl = dfsMax(left);
              int dr = dfsMax(right);
            
              if(dl <= dr) return dr +1;
              else return dl +1;
           }
           else if(right ==NULL && left != NULL){
               return dfsMax(left) +1;
           }
           else return dfsMax(right) +1;
        }
    }
    
};
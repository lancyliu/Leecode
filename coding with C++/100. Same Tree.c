/*
 @ Jun 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 100. Same Tree
* 
   Given two binary trees, write a function to check if they are equal or not.

   Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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
 
/**
There are several conditions:
1. both root are null, return true.
2. both root are not null: if the value not equal, return false.
                           if the value equal: consider the left/right children of two root.
						   1. four children are null, return true
						   2. left,left is null or right,right is null, check the not null subtree
						   3. four children are not null, check four subtree.
						   4. others are return false
3. other conditon: return false.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		
        if(p==NULL && q==NULL) return true;
        else if(p != NULL && q!= NULL){
            if(p->val == q->val){
                TreeNode *pleft = p->left;
                TreeNode *pright = p->right;
                TreeNode *qleft = q->left;
                TreeNode *qright = q->right;
                
                if(pleft == NULL && qleft ==NULL && pright ==NULL && qright==NULL) return true;
                else if(pleft == NULL && qleft ==NULL && pright !=NULL && qright!=NULL) return isSameTree(pright,qright);
                else if (pleft != NULL && qleft !=NULL && pright ==NULL && qright==NULL) return isSameTree(pleft,qleft);
                else if(pleft != NULL && qleft !=NULL && pright !=NULL && qright !=NULL) 
                return isSameTree(pleft,qleft) && isSameTree(pright,qright);
                else return false;
            }
            else return false;
        }
        else return false;
    }
};
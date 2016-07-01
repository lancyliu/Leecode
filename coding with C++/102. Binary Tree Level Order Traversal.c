/*
 @ Jun 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 102. Binary Tree Level Order Traversal
* 
   Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

   For example:
    Given binary tree [3,9,20,null,null,15,7],
       3
      / \
     9  20
       /  \
      15   7
   return its level order traversal as:
     [
      [3],
      [9,20],
      [15,7]
     ]

*/
	 


/*use Bredth first search to search the tree.*/

	 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root,&result,1);
        return result;
    }
    
	/**
	 root is the root of current tree/subtree
	 result store the result wanted
	 stage is the level of current node. use stage we can infer which vector should the value be stored in result.
	 stage start from 1.(this is : stage of root is 1)
	*/
    void bfs(TreeNode *root, vector<vector<int>> *result,int stage){
        if(root == NULL) return;
        
        if(stage == 1) {
            vector<int> temp;
            temp.push_back(root->val);
            result->push_back(temp);
        }
        TreeNode *left = root -> left;
        TreeNode *right = root -> right;

        if(left ==NULL && right ==NULL){
            return;
        }
        else if(left !=NULL && right ==NULL){
            //if the size is not bigger than stage, we should add a new vector in result. 
			//else we can derectly insert the value in the result.
			if(result->size() <= stage){
                vector<int> temp;
                temp.push_back(left->val);
                result->push_back(temp);
            }
            else{
                result->at(stage).push_back(left->val);
            }
			
            bfs(left, result, stage+1);
            return;
        }
        else if(right != NULL && left ==NULL){
            if(result->size() <= stage){
                vector<int> temp;
                temp.push_back(right->val);
                result->push_back(temp);
            }
            else{
                result->at(stage).push_back(right->val);
            }
			
            bfs(right, result, stage+1);
            return;
        }
        else{
			//both left and right is not null.
            if(result->size() <= stage){
                vector<int> temp;
                temp.push_back(left->val);
                temp.push_back(right->val);
                result->push_back(temp);
            }
            else{
                result->at(stage).push_back(left->val);
                result->at(stage).push_back(right->val);
            }
            bfs(left, result, stage+1);
            bfs(right, result, stage+1);
            return;
        }
    }
};
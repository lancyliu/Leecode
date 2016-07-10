/*
 @ July 9 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 107. Binary Tree Level Order Traversal II
* 
    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

    For example:
      Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
   return its bottom-up level order traversal as:
     [
      [15,7],
      [9,20],
      [3]
     ]

*/
	 



/**
use the same dfs function as Binary Tree Level Order Traversal I, just reverse the result.
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, &result, 1);
        
        vector<vector<int>> r;
        for(unsigned i=0; i<result.size(); i++){
            vector<int> temp = result.at(result.size()-1-i);
            r.push_back(temp);
        }
        return r;
        
    }
    
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
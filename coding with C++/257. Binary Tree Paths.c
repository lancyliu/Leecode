/*
 @ July 9 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 257. Binary Tree Paths
* 
    Given a binary tree, return all root-to-leaf paths.

   For example, given the following binary tree:

       1
     /   \
    2     3
     \
      5
   All root-to-leaf paths are:

   ["1->2->5", "1->3"]

*/
	 



/**
use the thought of bfs. just store the information of the path before bfs.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        bfs(root, &result);
        return result;
    }
    
    void bfs(TreeNode *root, vector<string> *result){
        //append this after the node->val if needed.
		string str ("->");
        if(root ==NULL) return;
        else if(root ->left ==NULL && root->right == NULL){
            //if both children node is null, then this node is a leaf node, store the val of this node into the last string in result vector.
			// why add to the last string? cause this leaf node does not create a new path, this node is an end of a path. since we use bfs.
			string s;
            string c = to_string(root->val);
            s.append(c);
			//if result vector is empty, we should add a new string in result.
            if(result->empty()){
            result->push_back(s);
            }
            else result->at(result->size()-1).append(s);
        }
        else if(root->left ==NULL && root->right != NULL){
            //if this node only has one child node, also do not create any new path.
			string s;
            string c = to_string(root->val);
            s.append(c);
            s.append(str);
            //cout<<s<<endl;
            if(result->empty()){
            result->push_back(s);
            }
            else result->at(result->size()-1).append(s);
            bfs(root->right,result);
        }
        else if(root->left !=NULL && root->right == NULL){
            string s;
            string c = to_string(root->val);
            s.append(c);
            s.append(str);
            if(result->empty()){
            result->push_back(s);
            }
            else result->at(result->size()-1).append(s);
            bfs(root->left,result);
        }
        else{
			//if this node has two children, then there will be two path, we should add one string in result vector.
            string s1;
            string c = to_string(root->val);
            s1.append(c);
            s1.append(str);
            if(result->empty()){
                result->push_back(s1);
                bfs(root->left,result);
                result->push_back(s1);
                bfs(root->right,result);
            }
            else{
                string base = result->at(result->size()-1);
                result->at(result->size()-1).append(s1);
                bfs(root->left,result);
                base.append(s1);
                result->push_back(base);
                bfs(root->right,result);
            }
        }
        return;
    }
    
};
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
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> inOrder;
    vector<int> print;
    while(root || !inOrder.empty()){
      if(root){
	inOrder.push(root);
	root = root->left;
      }
      else{
	root = inOrder.top();
	print.push_back(root->val);
	inOrder.pop();
	root = root->right;
      }
    }
    return print;
  }
};

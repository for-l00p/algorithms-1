/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
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
  vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> preOrder;
    vector<int> print;
    if(root) preOrder.push(root);
    while(!preOrder.empty()){
      TreeNode* root = preOrder.top();
      print.push_back(root->val);
      preOrder.pop();
      if(root->right) preOrder.push(root->right);
      if(root->left) preOrder.push(root->left);
    }
    return print;
  }
};

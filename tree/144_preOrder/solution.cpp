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

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> v;
    preOrder(root, v);
    return v;
  }
  void preOrder(TreeNode* root, vector<int> &v){
    if(!root) return;
    v.push_back(root->val);
    preOrder(root->left, v);
    preOrder(root->right, v);
  }
    
};

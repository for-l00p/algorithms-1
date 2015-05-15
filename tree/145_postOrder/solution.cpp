/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    postOrder(root, v);
    return v;
  }
  void postOrder(TreeNode* root, vector<int> &v){
    if(!root) return;
    postOrder(root->left, v);
    postOrder(root->right, v);
    v.push_back(root->val);
  }
};

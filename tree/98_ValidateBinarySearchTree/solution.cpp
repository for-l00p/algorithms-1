/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
  bool isValidBST(TreeNode* root) {
    return recursion(NULL, root, NULL);
  }
  bool recursion(TreeNode* left, TreeNode* root, TreeNode* right){
    if(!root) return true;
    if(left && left->val >= root->val || right && right->val <= root->val){
      return false;
    }
    return recursion(left, root->left, root) && recursion(root,root->right, right);
  }
};

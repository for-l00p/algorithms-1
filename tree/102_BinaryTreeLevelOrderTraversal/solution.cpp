/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Thanks to http://siddontang.gitbooks.io/leetcode-solution/content/tree/binary_tree_level_order_traversal.html
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result(maxDepth(root));
    preOrder(root, 0, result);
    return result;
  }
  int maxDepth(TreeNode* root){
    if(!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right))+1;
  }
  // like preOrder Traversal
  void preOrder(TreeNode* root, int level, vector<vector<int> >& result){
    if(!root) return;
    result[level].push_back(root->val);
    preOrder(root->left, level+1, result);
    preOrder(root->right, level+1, result);
  }
};

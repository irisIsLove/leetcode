/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30204
 *
 * [236] 二叉树的最近公共祖先
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    if (root == nullptr) {
      return root;
    }
    if (root == p || root == q) {
      return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr) {
      return root;
    } else if (left == nullptr && right != nullptr) {
      return right;
    } else if (left != nullptr && right == nullptr) {
      return left;
    }

    return nullptr;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

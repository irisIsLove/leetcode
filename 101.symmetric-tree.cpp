/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] 对称二叉树
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  bool isSymmetric(TreeNode* root) { return compare(root->left, root->right); }

private:
  bool compare(TreeNode* left, TreeNode* right)
  {
    if (left != nullptr && right == nullptr) {
      return false;
    } else if (left == nullptr && right != nullptr) {
      return false;
    } else if (left == nullptr && right == nullptr) {
      return true;
    } else if (left->val != right->val) {
      return false;
    }

    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);

    return outside && inside;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=30204
 *
 * [111] 二叉树的最小深度
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
#include <algorithm>
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
  int minDepth(TreeNode* root)
  {
    if (root == nullptr) {
      return 0;
    }

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (root->left != nullptr && root->right == nullptr) {
      return leftDepth + 1;
    }
    if (root->left == nullptr && root->right != nullptr) {
      return rightDepth + 1;
    }

    return std::min(leftDepth, rightDepth) + 1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */

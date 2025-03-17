/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30204
 *
 * [110] 平衡二叉树
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
#include <algorithm>
#include <cstdlib>

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
  bool isBalanced(TreeNode* root) { return getHeight(root) != -1; }

private:
  int getHeight(TreeNode* node)
  {
    if (node == nullptr) {
      return 0;
    }

    int leftHeight = getHeight(node->left);
    if (leftHeight == -1) {
      return -1;
    }

    int rightHeight = getHeight(node->right);
    if (rightHeight == -1) {
      return -1;
    }

    if (std::abs(leftHeight - rightHeight) > 1) {
      return -1;
    }

    return std::max(leftHeight, rightHeight) + 1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 * @lcpr version=30204
 *
 * [112] 路径总和
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
  bool hasPathSum(TreeNode* root, int targetSum)
  {
    if (root == nullptr) {
      return false;
    }

    bool isLeaf = root->left == nullptr && root->right == nullptr;
    int count = targetSum - root->val;
    if (isLeaf && count == 0) {
      return true;
    }

    if (isLeaf && count != 0) {
      return false;
    }

    if (root->left != nullptr) {
      if (hasPathSum(root->left, count))
        return true;
    }

    if (root->right != nullptr) {
      if (hasPathSum(root->right, count))
        return true;
    }

    return false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

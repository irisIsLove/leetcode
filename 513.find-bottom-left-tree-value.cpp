/*
 * @lc app=leetcode.cn id=513 lang=cpp
 * @lcpr version=30204
 *
 * [513] 找树左下角的值
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
#include <cstdint>
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
  int findBottomLeftValue(TreeNode* root)
  {
    recurse(root, 0);

    return result_;
  }

private:
  void recurse(TreeNode* node, int depth)
  {
    if (node->left == nullptr && node->right == nullptr) {
      if (depth > maxDepth_) {
        maxDepth_ = depth;
        result_ = node->val;
      }
    }

    if (node->left != nullptr) {
      recurse(node->left, depth + 1);
    }

    if (node->right != nullptr) {
      recurse(node->right, depth + 1);
    }
  }

private:
  int result_;
  int maxDepth_ = INT32_MIN;
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,5,6,null,null,7]\n
// @lcpr case=end

 */

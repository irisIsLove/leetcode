/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=30204
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
#include <algorithm>
#include <climits>

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
  int getMinimumDifference(TreeNode* root)
  {
    recurse(root);
    return result_;
  }

private:
  void recurse(TreeNode* node)
  {
    if (node == nullptr) {
      return;
    }

    recurse(node->left);
    if (pre_ != nullptr) {
      result_ = std::min(result_, node->val - pre_->val);
    }
    pre_ = node;
    recurse(node->right);
  }

private:
  int result_ = INT_MAX;
  TreeNode* pre_ = nullptr;
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=30204
 *
 * [501] 二叉搜索树中的众数
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
#include <vector>
using namespace std;
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
  vector<int> findMode(TreeNode* root)
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
    if (pre_ != nullptr && pre_->val == node->val) {
      ++count_;
    } else {
      count_ = 1;
    }
    if (count_ == maxCount_) {
      result_.push_back(node->val);
    } else if (count_ > maxCount_) {
      maxCount_ = count_;
      result_.clear();
      result_.push_back(node->val);
    }
    pre_ = node;
    recurse(node->right);
  }

private:
  int count_ = 0;
  int maxCount_ = 0;
  TreeNode* pre_ = nullptr;
  std::vector<int> result_;
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

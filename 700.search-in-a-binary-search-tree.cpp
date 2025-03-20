/*
 * @lc app=leetcode.cn id=700 lang=cpp
 * @lcpr version=30204
 *
 * [700] 二叉搜索树中的搜索
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
  TreeNode* searchBST(TreeNode* root, int val)
  {
    while (root != nullptr) {
      if (root->val > val) {
        root = root->left;
      } else if (root->val < val) {
        root = root->right;
      } else {
        return root;
      }
    }

    return nullptr;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

 */

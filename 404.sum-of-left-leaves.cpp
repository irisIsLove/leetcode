/*
 * @lc app=leetcode.cn id=404 lang=cpp
 * @lcpr version=30204
 *
 * [404] 左叶子之和
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
  int sumOfLeftLeaves(TreeNode* root)
  {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
      return 0;
    }

    int leftNum = sumOfLeftLeaves(root->left);
    if (root->left != nullptr && root->left->left == nullptr &&
        root->left->right == nullptr) {
      leftNum = root->left->val;
    }

    int rightNum = sumOfLeftLeaves(root->right);

    return leftNum + rightNum;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

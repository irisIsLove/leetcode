/*
 * @lc app=leetcode.cn id=222 lang=cpp
 * @lcpr version=30204
 *
 * [222] 完全二叉树的节点个数
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
  int countNodes(TreeNode* root)
  {
    if (root == nullptr) {
      return 0;
    }

    TreeNode* leftNode = root->left;
    TreeNode* rightNode = root->right;
    int leftDepth = 0, rigthDepth = 0;

    while (leftNode != nullptr) {
      leftNode = leftNode->left;
      ++leftDepth;
    }

    while (rightNode != nullptr) {
      rightNode = rightNode->right;
      ++rigthDepth;
    }

    if (leftDepth == rigthDepth) {
      return (2 << leftDepth) - 1;
    }

    int leftNums = countNodes(root->left);
    int rightNums = countNodes(root->right);

    return leftNums + rightNums + 1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

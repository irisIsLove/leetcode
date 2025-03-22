/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30204
 *
 * [450] 删除二叉搜索树中的节点
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
  TreeNode* deleteNode(TreeNode* root, int key)
  {
    if (root == nullptr) {
      return nullptr;
    }

    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      } else if (root->left != nullptr && root->right == nullptr) {
        TreeNode* result = root->left;
        delete root;
        return result;
      } else if (root->left == nullptr && root->right != nullptr) {
        TreeNode* result = root->right;
        delete root;
        return result;
      } else {
        TreeNode* cur = root->right;
        while (cur->left != nullptr) {
          cur = cur->left;
        }
        cur->left = root->left;

        TreeNode* result = root->right;
        delete root;
        return result;
      }
    }

    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

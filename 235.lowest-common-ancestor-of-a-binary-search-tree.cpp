/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30204
 *
 * [235] 二叉搜索树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    if (root == nullptr) {
      return nullptr;
    }

    if (root->val > p->val && root->val > q->val) {
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      if (left != nullptr) {
        return left;
      }
    }

    if (root->val < p->val && root->val < q->val) {
      TreeNode* right = lowestCommonAncestor(root->right, p, q);
      if (right != nullptr) {
        return right;
      }
    }

    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30204
 *
 * [94] 二叉树的中序遍历
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
#include <stack>
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
  vector<int> inorderTraversal(TreeNode* root)
  {
    if (root == nullptr) {
      return {};
    }

    std::vector<int> result;
    std::stack<TreeNode*> stack;

    TreeNode* cur = root;
    while (cur != nullptr || !stack.empty()) {
      if (cur != nullptr) {
        stack.push(cur);
        cur = cur->left;
      } else {
        cur = stack.top();
        stack.pop();
        result.push_back(cur->val);
        cur = cur->right;
      }
    }

    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

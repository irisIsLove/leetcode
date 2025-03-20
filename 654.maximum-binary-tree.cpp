/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30204
 *
 * [654] 最大二叉树
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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums)
  {
    if (nums.size() == 1) {
      return new TreeNode(nums[0]);
    }

    int index = -1;
    int maxValue = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > maxValue) {
        index = i;
        maxValue = nums[i];
      }
    }

    TreeNode* root = new TreeNode(maxValue);
    if (index > 0) {
      std::vector<int> leftSubVec(nums.begin(), nums.begin() + index);
      root->left = constructMaximumBinaryTree(leftSubVec);
    }
    if (index < nums.size() - 1) {
      std::vector<int> rightSubVec(nums.begin() + index + 1, nums.end());
      root->right = constructMaximumBinaryTree(rightSubVec);
    }

    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */

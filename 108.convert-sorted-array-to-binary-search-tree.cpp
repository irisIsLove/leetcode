/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30204
 *
 * [108] 将有序数组转换为二叉搜索树
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
  TreeNode* sortedArrayToBST(vector<int>& nums)
  {
    return buildTree(nums, 0, nums.size() - 1);
  }

private:
  TreeNode* buildTree(std::vector<int>& nums, int begin, int end)
  {
    if (begin > end) {
      return nullptr;
    }

    int mid = (begin + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, begin, mid - 1);
    root->right = buildTree(nums, mid + 1, end);

    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

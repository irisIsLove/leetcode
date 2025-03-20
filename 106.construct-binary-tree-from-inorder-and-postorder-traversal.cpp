/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30204
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
  {
    if (inorder.empty()) {
      return nullptr;
    }

    if (inorder.size() == 1) {
      TreeNode* root = new TreeNode(postorder[0]);
      return root;
    }

    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);

    int index = 0;
    for (; index < inorder.size(); ++index) {
      if (inorder[index] == rootValue) {
        break;
      }
    }

    std::vector<int> leftSubInorder(inorder.begin(), inorder.begin() + index);
    std::vector<int> leftSubPostorder(postorder.begin(),
                                      postorder.begin() + index);
    root->left = buildTree(leftSubInorder, leftSubPostorder);

    std::vector<int> rightSubInorder(inorder.begin() + index + 1,
                                     inorder.end());
    std::vector<int> rightSubPostorder(postorder.begin() + index,
                                       postorder.end() - 1);
    root->right = buildTree(rightSubInorder, rightSubPostorder);

    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

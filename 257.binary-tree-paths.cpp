/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=30204
 *
 * [257] 二叉树的所有路径
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
#include <string>
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
  vector<string> binaryTreePaths(TreeNode* root)
  {
    if (root == nullptr) {
      return {};
    }

    std::vector<std::string> result;
    std::vector<int> path;
    backtrack(root, path, result);

    return result;
  }

private:
  void backtrack(TreeNode* node,
                 std::vector<int> path,
                 std::vector<std::string>& result)
  {
    path.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      std::string strPath;

      for (int i = 0; i < path.size() - 1; ++i) {
        strPath.append(std::to_string(path[i]) + "->");
      }
      strPath.append(std::to_string(path[path.size() - 1]));
      result.push_back(strPath);

      return;
    }

    if (node->left != nullptr) {
      backtrack(node->left, path, result);
    }

    if (node->right != nullptr) {
      backtrack(node->right, path, result);
    }
    path.pop_back();
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

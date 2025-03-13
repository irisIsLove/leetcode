/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30204
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lcpr-template-start
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  string removeDuplicates(string s)
  {
    std::string result;

    for (char c : s) {
      if (result.empty() || result.back() != c) {
        result.push_back(c);
      } else {
        result.pop_back();
      }
    }

    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */

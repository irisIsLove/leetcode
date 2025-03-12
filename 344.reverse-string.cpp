/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30204
 *
 * [344] 反转字符串
 */

// @lcpr-template-start
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  void reverseString(vector<char>& s)
  {
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
      std::swap(s[i], s[j]);
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30204
 *
 * [541] 反转字符串 II
 */

// @lcpr-template-start
#include <string>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  string reverseStr(string s, int k)
  {
    std::string result;

    for (int i = 0; i < s.size(); i += 2 * k) {
      std::string str = s.substr(i, 2 * k);

      if (str.size() >= k) {
        std::reverse(str.begin(), str.begin() + k);
      } else {
        std::reverse(str.begin(), str.end());
      }
      result.append(str);
    }

    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcdefg"\n8\n
// @lcpr case=end

 */

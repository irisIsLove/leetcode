// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30204
 *
 * [151] 反转字符串中的单词
 */

// @lcpr-template-start
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  string reverseWords(string s)
  {
    trim(s);
    std::reverse(s.begin(), s.end());

    int begin = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        std::reverse(s.begin() + begin, s.begin() + i);
        begin = i + 1;
      }
    }
    std::reverse(s.begin() + begin, s.end());

    return s;
  }

private:
  void trim(string& s)
  {
    int slow = 0;

    for (int fast = 0; fast < s.size(); ++fast) {
      if (s[fast] != ' ') {
        if (slow != 0) {
          s[slow] = ' ';
          ++slow;
        }

        while (fast < s.size() && s[fast] != ' ') {
          s[slow] = s[fast];
          ++slow;
          ++fast;
        }
      }
    }

    s.resize(slow);
  }
};
// @lc code=end

/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

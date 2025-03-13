// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 * @lcpr version=30204
 *
 * [459] 重复的子字符串
 */

// @lcpr-template-start
#include <string>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    vector<int> next(s.size());
    getNext(next, s);

    if (next[s.size() - 1] == 0) {
      return false;
    }

    return s.size() % (s.size() - next[s.size() - 1]) == 0;
  }

private:
  void getNext(vector<int>& next, const string& s)
  {
    int prefix = 0;
    next[prefix] = 0;

    for (int suffix = 1; suffix < s.size(); ++suffix) {
      while (prefix > 0 && s[prefix] != s[suffix]) {
        prefix = next[prefix - 1];
      }

      if (s[prefix] == s[suffix]) {
        ++prefix;
      }

      next[suffix] = prefix;
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcabcabc"\n
// @lcpr case=end

 */

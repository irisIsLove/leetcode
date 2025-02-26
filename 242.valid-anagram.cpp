// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30204
 *
 * [242] 有效的字母异位词
 */

// @lcpr-template-start
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size()) {
      return false;
    }

    int hash[26];
    for (char c : s) {
      hash[c - 'a']++;
    }
    for (char c : t) {
      hash[c - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
      if (hash[i] != 0) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */

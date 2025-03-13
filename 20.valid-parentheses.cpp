/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
 */

// @lcpr-template-start
#include <stack>
#include <string>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  bool isValid(string s)
  {
    std::stack<char> stack;

    for (char c : s) {
      if (c == '(') {
        stack.push(')');
      } else if (c == '{') {
        stack.push('}');
      } else if (c == '[') {
        stack.push(']');
      } else {
        if (stack.empty() || stack.top() != c) {
          return false;
        } else {
          stack.pop();
        }
      }
    }

    return stack.empty();
  }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */

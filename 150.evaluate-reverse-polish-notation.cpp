/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
 */

// @lcpr-template-start
#include <stack>
#include <string>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  int evalRPN(vector<string>& tokens)
  {
    std::stack<int> stack;

    for (const std::string& token : tokens) {
      if (token == "+") {
        int num1 = stack.top();
        stack.pop();
        int num2 = stack.top();
        stack.pop();

        stack.push(num2 + num1);
      } else if (token == "-") {
        int num1 = stack.top();
        stack.pop();
        int num2 = stack.top();
        stack.pop();

        stack.push(num2 - num1);
      } else if (token == "*") {
        int num1 = stack.top();
        stack.pop();
        int num2 = stack.top();
        stack.pop();

        stack.push(num2 * num1);
      } else if (token == "/") {
        int num1 = stack.top();
        stack.pop();
        int num2 = stack.top();
        stack.pop();

        stack.push(num2 / num1);
      } else {
        stack.push(std::stoi(token));
      }
    }

    return stack.top();
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

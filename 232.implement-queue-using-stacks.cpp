/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30204
 *
 * [232] 用栈实现队列
 */

// @lcpr-template-start
#include <stack>
using namespace std;
// @lcpr-template-end
// @lc code=start
class MyQueue
{
public:
  MyQueue() {}

  void push(int x) { in.push(x); }

  int pop()
  {
    int top = peek();
    out.pop();
    return top;
  }

  int peek()
  {
    if (out.empty()) {
      while (!in.empty()) {
        int n = in.top();
        in.pop();
        out.push(n);
      }
    }

    return out.top();
  }

  bool empty() { return in.empty() && out.empty(); }

private:
  std::stack<int> in;
  std::stack<int> out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [],
[]]\n
// @lcpr case=end

 */

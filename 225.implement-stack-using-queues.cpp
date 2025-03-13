// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30204
 *
 * [225] 用队列实现栈
 */

// @lcpr-template-start
#include <queue>
using namespace std;
// @lcpr-template-end
// @lc code=start
class MyStack
{
public:
  MyStack() {}

  void push(int x) { queue.push(x); }

  int pop()
  {
    int size = queue.size() - 1;

    for (int i = 0; i < size; ++i) {
      queue.push(queue.front());
      queue.pop();
    }

    int front = queue.front();
    queue.pop();

    return front;
  }

  int top()
  {
    int top = pop();
    push(top);
    return top;
  }

  bool empty() { return queue.empty(); }

private:
  std::queue<int> queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"]\n[[], [1], [2], [], [],
[]]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
 */

// @lcpr-template-start
#include <deque>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    MonotoneQueue queue;
    vector<int> result;

    for (int i = 0; i < nums.size() - k + 1; ++i) {
      if (i == 0) {
        for (int j = 0; j < k; ++j) {
          queue.push(nums[j]);
        }
        result.push_back(queue.getMaxValue());
      } else {
        queue.pop(nums[i - 1]);
        queue.push(nums[i + k - 1]);
        result.push_back(queue.getMaxValue());
      }
    }

    return result;
  }

private:
  class MonotoneQueue
  {
  public:
    void pop(int value)
    {
      if (!queue.empty() && value == queue.front()) {
        queue.pop_front();
      }
    }

    void push(int value)
    {
      while (!queue.empty() && value > queue.back()) {
        queue.pop_back();
      }
      queue.push_back(value);
    }

    int getMaxValue() { return queue.front(); }

  private:
    std::deque<int> queue;
  };
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] 长度最小的子数组
 */

// @lcpr-template-start
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  int minSubArrayLen(int target, vector<int>& nums)
  {
    int begin = 0;
    int sum = 0;
    int length = INT32_MAX;

    for (int end = 0; end < nums.size(); ++end) {
      sum += nums[end];
      while (sum >= target) {
        int curLength = end - begin + 1;
        if (curLength < length)
          length = curLength;

        sum -= nums[begin];
        ++begin;
      }
    }

    return length == INT32_MAX ? 0 : length;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

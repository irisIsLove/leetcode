/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30204
 *
 * [35] 搜索插入位置
 */

// @lcpr-template-start
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  int searchInsert(vector<int>& nums, int target)
  {
    int left = 0, right = nums.size();
    int mid = left + ((right - left) >> 2);
    while (left < right) {
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid;
      } else {
        return mid;
      }
      mid = left + ((right - left) >> 2);
    }
    return mid;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */

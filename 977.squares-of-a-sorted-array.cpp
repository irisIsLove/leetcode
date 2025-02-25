/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30204
 *
 * [977] 有序数组的平方
 */

// @lcpr-template-start
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  vector<int> sortedSquares(vector<int>& nums)
  {
    std::vector<int> result(nums.size());

    int curLocation = nums.size() - 1;
    int right = nums.size() - 1;
    int left = 0;

    while (curLocation >= 0) {
      if (std::abs(nums[left]) < std::abs(nums[right])) {
        result[curLocation] = nums[right] * nums[right];
        --right;
      } else {
        result[curLocation] = nums[left] * nums[left];
        ++left;
      }
      --curLocation;
    }

    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 三数之和
 */

// @lcpr-template-start
#include <algorithm>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        break;
      }

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int target = nums[i] + nums[left] + nums[right];

        if (target > 0) {
          --right;
        } else if (target < 0) {
          ++left;
        } else {
          result.push_back({ nums[i], nums[left], nums[right] });

          while (left < right && nums[left] == nums[left + 1])
            ++left;
          while (left < right && nums[right] == nums[right - 1])
            --right;

          ++left;
          --right;
        }
      }
    }

    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

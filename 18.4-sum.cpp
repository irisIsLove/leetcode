/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 四数之和
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
  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (target > 0 && nums[i] > target) {
        break;
      }

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      auto num1 = static_cast<std::int64_t>(nums[i]);
      for (int j = i + 1; j < nums.size(); ++j) {
        auto num2 = static_cast<std::int64_t>(nums[j]);
        if (target > 0 && (num1 + num2) > target) {
          break;
        }

        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) {
          std::int64_t sum = num1 + num2 + nums[left] + nums[right];

          if (sum > target) {
            --right;
          } else if (sum < target) {
            ++left;
          } else {
            result.push_back({ nums[i], nums[j], nums[left], nums[right] });

            while (left < right && nums[left] == nums[left + 1])
              ++left;
            while (left < right && nums[right] == nums[right - 1])
              --right;

            ++left;
            --right;
          }
        }
      }
    }

    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */

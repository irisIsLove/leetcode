/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30204
 *
 * [1] 两数之和
 */

// @lcpr-template-start
#include <unordered_map>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); ++i) {
      auto iter = hash.find(target - nums[i]);
      if (iter != hash.end()) {
        return { iter->second, i };
      }
      hash.emplace(nums[i], i);
    }

    return {};
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

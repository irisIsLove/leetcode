/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30204
 *
 * [349] 两个数组的交集
 */

// @lcpr-template-start
#include <unordered_set>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
  {
    std::unordered_set<int> result;
    bool hash[1001] = { false };

    for (int num : nums1) {
      hash[num] = true;
    }

    for (int num : nums2) {
      if (hash[num]) {
        result.insert(num);
      }
    }

    return { result.begin(), result.end() };
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */

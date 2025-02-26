/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30204
 *
 * [454] 四数相加 II
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
  int fourSumCount(vector<int>& nums1,
                   vector<int>& nums2,
                   vector<int>& nums3,
                   vector<int>& nums4)
  {
    int count = 0;
    std::unordered_map<int, int> hash;

    for (int num1 : nums1) {
      for (int num2 : nums2) {
        hash[num1 + num2]++;
      }
    }

    for (int num3 : nums3) {
      for (int num4 : nums4) {
        int target = 0 - (num3 + num4);
        if (hash.find(target) != hash.end()) {
          count += hash[target];
        }
      }
    }

    return count;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2]\n[-2,-1]\n[-1,2]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n[0]\n[0]\n
// @lcpr case=end

 */

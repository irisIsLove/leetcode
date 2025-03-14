/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30204
 *
 * [347] 前 K 个高频元素
 */

// @lcpr-template-start
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
  using Kv = std::pair<int, int>;

public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    auto cmp = [](const Kv& lhs, const Kv& rhs) {
      return lhs.second > rhs.second;
    };

    std::unordered_map<int, int> map;
    for (int num : nums) {
      map[num]++;
    }

    std::priority_queue<Kv, std::vector<Kv>, decltype(cmp)> queue(cmp);
    for (const auto& it : map) {
      queue.push(it);
      if (queue.size() > k) {
        queue.pop();
      }
    }

    std::vector<int> result(k);
    for (int i = k - 1; i >= 0; --i) {
      result[i] = queue.top().first;
      queue.pop();
    }

    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

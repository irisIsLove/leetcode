/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30204
 *
 * [59] 螺旋矩阵 II
 */

// @lcpr-template-start
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    int x = 0, y = 0;
    int num = 1;
    int offset = 0;
    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    while (n > 1) {
      for (; y < n + offset - 1; ++y) {
        result[x][y] = num;
        ++num;
      }

      for (; x < n + offset - 1; ++x) {
        result[x][y] = num;
        ++num;
      }

      for (; y > 0 + offset; --y) {
        result[x][y] = num;
        ++num;
      }

      for (; x > 0 + offset; --x) {
        result[x][y] = num;
        ++num;
      }

      n -= 2;
      ++x, ++y;
      ++offset;
    }

    if (n == 1) {
      result[x][y] = num;
    }

    return result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 20\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (77.73%)
 * Likes:    594
 * Dislikes: 0
 * Total Accepted:    158.2K
 * Total Submissions: 203.6K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1
 * 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

#include <vector>
using std::vector;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int startx = 0, starty = 0;
    int mid = n / 2;
    int loop = n / 2;
    int offset = n - 1;
    int cnt = 1;
    int i, j;
    while (loop-- > 0) {
      i = startx;
      j = starty;
      for (j = starty; j < starty + offset; j++) {
        res[i][j] = cnt++;
      }
      for (i = startx; i < startx + offset; i++) {
        res[i][j] = cnt++;
        /* code */
      }
      for (; j > starty; j--) {
        res[i][j] = cnt++;
      }
      for (; i > startx; i--) {
        res[i][j] = cnt++;
      }
      startx++;
      starty++;
      offset -= 2;
    }
    if (n % 2 == 1) {
      res[mid][mid] = cnt++;
    }

    return res;
  }
};

int main(){
    Solution s;
    s.generateMatrix(4);
    return 0;
}
// @lc code=end

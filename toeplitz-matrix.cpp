#include "./com/header.h"

// https://leetcode.com/problems/toeplitz-matrix/
/*
Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
*/

// 如果一个矩阵从左上角到右下角的每个对角线具有相同的元素 它就是toeplitz-matrix

// solution 1:
/*  如果matrix[x1][y1] 与 matrix[x2][y2]在一条对角线上，
 *  那么 x1 - y1= x2 - y2;
 * [5,5] : matrix[1][0] 与 matrix[2][1]
 * [1, 1, 1]:  matrix[0][0], matrix[1][1] matrix[2][2]
 */
// 这个题要求判断是否是toeplitz matrix 所以可以使用哈希记录x-y => value
// 然后遍历整个矩阵，检查当前值与其下标差的在哈希中存储的值是否匹配
// 总结：我在知道这个规则后为什么写不出代码？因为我在纠结如何按照对角线去遍历整个矩阵，发现很难写出按照对角线遍历的代码
// 对于M行N列的teoplitz矩阵，时间复杂度：O(M*N) 空间复杂度 O(M+N)
bool isToeplitzMatrix(vector<vector<int>> &matrix)
{
  int rows = matrix.size(), lines = matrix[0].size();
  map<int, int> match;
  for (int r = 0; r < rows; r++)
  {
    for (int l = 0; l < lines; l++)
    {
      int s = r - l;
      if (match.find(s) == match.end())
      {
        match[s] = matrix[r][l];
      }
      else
      {
        if (match[s] != matrix[r][l])
        {
          return false;
        }
      }
    }
  }
  return true;
}

// solution 2:
// 对于每个元素，与其在同一个对角线上的元素位于其左上方，那么可以遍历数组,检查每个元素其左上方的元素语气是否相等
// 对于M行N列的teoplitz矩阵，时间复杂度：O(M*N) 空间复杂度 O(1)
bool isToeplitzMatrix_v2(vector<vector<int>> &matrix)
{
  int rows = matrix.size(), lines = matrix[0].size();
  for (int r(0); r < rows; ++r)
  {
    for (int l(0); l < lines; ++l)
    {
      if (r < 1 || l < 1)
        continue;
      if (matrix[r][l] != matrix[r - 1][l - 1])
        return false;
    }
  }
  return true;
}

// 那么 到底如何按照对角线遍历矩阵呢？

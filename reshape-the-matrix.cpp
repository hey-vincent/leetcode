#include "./com/header.h"

// 矩阵变形： 将 一个矩阵变成 r行c列的矩阵
// Solution：1. 使用队列将所有元素读入队列，再编排到新矩阵中
// Solution：2. 或者直接索引下标来变形

vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
  int rows = nums.size(), cols = nums[0].size();
  if (r * c != rows * cols)
    return nums;

  vector<int> nc(cols, INT_MIN);
  vector<vector<int>> matrix(rows, nc);
  int count = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix[count / c][count % c] = nums[i][j];
      count++;
    }
  }
  return matrix;
}

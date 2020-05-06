#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/transpose-matrix/
// 翻转二维数组：
// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]

// Solution: 外层循环列 内层循环行 每次循环的情况是：列固定，行变化

vector<vector<int>> transpose(vector<vector<int>> &A) {
  vector<vector<int>> v;
  for (int line = 0; line < A[0].size(); line++) {
    vector<int> v_lines(row, INT_MIN);
    for (int row = 0; row < A.size(); row++) {
      v_lines[row] = A[row][line];
    }
    v.push_back(v_lines);
  }
  return v;
}

vector<vector<int>> transpose_beautify(vector<vector<int>> &A) {
  int rows = A.size(), lines = A[0].size();
  vector<vector<int>> res(lines);
  for (int l = 0; l < lines; l++) {
    vector<int> le(rows, INT_MIN);
    for (int r = 0; r < rows; r++) {
      le[r] = A[r][l];
    }
    res[l] = le;
  }
  return res;
}

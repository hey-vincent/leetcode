#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/sort-array-by-parity-ii/
// 已知一个数组：一半奇数一半偶数
// 调整数组使得：奇数位置对应的是奇数  偶数位置对应的是偶数
// solution：
//          1. 奇数位置如果调整好了 偶数位置也就调整好了

vector<int> sortArrayByParityII(vector<int> &A) {
  int i = 0, j = 1;
  while (i < A.size()) {
    if (A[i] % 2 != 0) {
      while (A[j] % 2 == 1) {
        j += 2;
      }
      iter_swap(A.begin() + i, A.begin() + j);
    }

    i += 2;
  }

  return A;
}

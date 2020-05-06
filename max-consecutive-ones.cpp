#include "./com/header.h"

/*
https://leetcode.com/problems/max-consecutive-ones/

Given a binary array, find the maximum number of consecutive 1s in this array.

给定一个01数组，输出最大连续的1子串长度
*/

// 不要纠结使用双指针，双指针的问题在于 尾部不好处理

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int c = 0, i = 0, ret = 0;

  while (i < nums.size())
  {
    if (nums[i] == 1)
      ret = max(++c, ret);
    else
      c = 0;
    i++;
  }

  return ret;
}

int findMaxConsecutiveOnes_v2(vector<int> &nums)
{
  int i = 0, j = 0, len = nums.size(), m = 0;
  while (j < len)
  {
    if (1 != nums[j] || j == len - 1)
    {
      m = max(m, j - i);
      i = j + 1;
    }
    j++;
  }

  return m;
}

int main()
{
  int x[] = {1, 0, 1, 1, 0, 1};
  vector<int> A(x, x + sizeof(x) / sizeof(int));
  printf("%d\n", findMaxConsecutiveOnes(A));
  cout << findMaxConsecutiveOnes_v2(A);
}

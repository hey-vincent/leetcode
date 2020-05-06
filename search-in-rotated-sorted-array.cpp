#include "./com/header.h"
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/
// [6,7,8,9,11,20,1,2,4]
// 一个升序序的数组 其中一部分被旋转到右侧了
// 要求：O(logN)搜索出target
// 思路：按正常的二分查找去搜索，
// 每次中中间分割，旋转点必然落在两段中的其中一段
// 对正常顺序的那部分比较，可以淘汰两段中其中一段

int search(vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1, mid = 0;

  while (left <= right) {
    mid = (left + right) / 2;
    if (target == nums[mid])
      return mid;

    if (nums[mid] < nums[right]) {
      if (nums[mid] <= target && target <= nums[right])
        left = mid + 1;
      else
        right = mid - 1;
    } else {
      if (nums[left] <= target && target <= nums[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
  }

  return -1;
}

// high votes
int search_v1(vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    int mid = (r - l) / 2 + l;
    if (nums[mid] == target)
      return mid;

    // 如果中间 小于 右侧：反转点在左侧， 右侧有序
    if (nums[mid] < nums[r]) {
      // 如果中间数小于 target 且 右侧大于target，就是说target 可能在右半部分
      if (nums[mid] < target && target <= nums[r])
        l = mid + 1;
      else
        r = mid - 1;
    } else // 左侧有序，反转点在右侧
    {
      // 可能在左侧有序区域内
      if (nums[l] <= target && target < nums[mid])
        r = mid - 1;
      else
        l = mid + 1;
    }
  }
  return -1;
}

#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// 删除有序数组中的重复元素，并返回元素个数
// 要求只允许使用O(1)的额外空间
// input: [0,0,1,1,1,2,2,3,3,4] output = 5
// 思路：距离相差1的快慢指针 i j
// 如果 i = j 说明重复，i 停下 j向后找到第一个不重复的元素 nums[i+1] = nums[j]
// 然后 i 向后移动，与j重复做以上动作

int removeDuplicates(vector<int> &nums)
{
    int length = nums.size();
    int i(0), j(1);
    for (; j < length; ++j)
    {
        if (nums[i] != nums[j])
        {
            ++i;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}
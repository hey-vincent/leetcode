#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/remove-element/
// 给定一无序数组 nums，和一个元素 val， 删除 nums 中所有的val并返回长度，O(1)空间
// nums = [0,1,2,2,3,0,4,2], val = 2, nums = [0, 1, 3, 0, 4]

// solution-1: 头尾指针
int removeElement(vector<int> &nums, int val)
{
    int len = nums.size();
    if (0 == len)
        return 0;

    int i(0), j(len - 1);
    while (j >= i)
    {
        if (val != nums[i])
        {
            i++;
            continue;
        }

        if (val == nums[j])
        {
            j--;
            continue;
        }

        int n = nums[i];
        nums[i] = nums[j];
        nums[j] = n;
    }
    return j + 1;
}

// solution-2： 快慢指针，慢指针遇到val停下，快指针向前找非val的数 复制过来
// 如果
int removeElementV2(vector<int> &nums, int val)
{
    int len = nums.size();
    if (0 == len)
        return 0;

    int i(0), j(0);
    while (j < len)
    {
        if (val != nums[j])
        {
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    return j + 1;
}
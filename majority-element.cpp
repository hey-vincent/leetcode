#include "./com/header.h"

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
Input: [2,2,1,1,1,2,2]
Output: 2
*/

int majorityElement(vector<int> &nums)
{
    map<int, int> dict;
    int len = nums.size();
    for (int i = 0; i < len; ++i)
    {
        if (dict.find(nums[i]) == dict.end())
        {
            dict[nums[i]] = 1;
        }
        else
        {
            dict[nums[i]]++;
        }
        if (dict[nums[i]] > len / 2)
        {
            return nums[i];
        }
    }
    return 0;
}

int main()
{
    vector<int> v;
    majorityElement(v);
    return 0;
}
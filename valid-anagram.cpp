#include "com/header.h"
//https://leetcode.com/problems/valid-anagram/
/*
    Given two strings s and t,
    write a function to determine if t is an anagram of s.

    Example 1 :

    Input : s = "anagram",
            t = "nagaram" Output : true Example 2 :

    Input : s = "rat",
            t = "car" Output : false Note : You may assume the string contains only lowercase alphabets.

                                            Follow up : What if the inputs contain unicode characters
            ? How would you adapt your solution to such case
            ?
*/

// 思路： 如果s中某个位置i的字符出现次数++，将t中对应位置字符出现次数--
// 如果 s 和 t是symmetric 的话，最终各个字符出现次数为0
// 因为两个串中的字符和出现次数都是一致的，即使某个位置不一样，++ -- 最终会抵消为0
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int counter[256] = {0};

    for (int left = 0, i = 0; i < t.size(); i++)
    {
        counter[s.at(i)]++;
        counter[t.at(i)]--;
    }
    for (int j = 0; j < 256; j++)
    {
        if (counter[j] != 0)
            return false;
    }
    return true;
}

// 排序法
bool isAnagram_Sort(string s, string t)
{
    if (s.size() != t.size())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
            return false;
    }

    return true;
}
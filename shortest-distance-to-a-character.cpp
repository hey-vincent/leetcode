#include "./com/header.h"
// https://leetcode.com/problems/shortest-distance-to-a-character/
// shortest-distance-to-a-character

/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
*/

// 从前到后，依次计算某个位置之前的C字符之间的距离
// 从后到前，计算某个位置之后的第一个C字符与目前存储的之前C字符之间的min值

vector<int> minArray(string S, char C)
{

    vector<int> prev(S.size(), INT_MAX);
    int last = INT_MAX;
    for (int i = 0; i < S.size(); i++)
    {
        if (S.at(i) == C)
            last = i;
        prev[i] = abs(i - last);
    }

    int after = INT_MAX;
    for (int i = S.size() - 1; i >= 0; i--)
    {
        if (S.at(i) == C)
            after = i;
        prev[i] = min(prev[i], abs(after - i));
    }
    return prev;
}

int main()
{

    string s = "loveleetcode";
    char c = 'e';

    vector<int> r = minArray(s, c);
    printVector(r);
}

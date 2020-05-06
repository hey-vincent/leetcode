#include "com/header.h"
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

// 对了一小半，抓住了特征：两个串如果是通字符乱序串，那么他们满足一个条件，两个中所有字符的出现次数相等
vector<int> findAnagrams(string s, string p)
{
    map<char, int> m;
    for (int j = 0; j < p.size(); j++)
    {
        m[p.at(j)]++;
    }
    vector<int> res;
    // 暴力法的问题：
    // 1. 需要判断s中长度 = p.size() 的子串sub, p中的每个字符在sub中都能找到且数量相等
    for (int i = 0; i < s.size() - p.size(); i++)
    {
        string sub = s.substr(i, p.size());
        map<char, int> tmp;
        for (int k = 0; k < p.size(); k++)
        {
            tmp[sub.at(k)]++;
        }
        map<char, int>::iterator it = tmp.begin();
        for (; it != tmp.end(); it++)
        {
            if (m[it->first] != it->second)
            {
                break;
            }
        }

        if (it == tmp.end())
            res.push_back(i);
    }
    return res;
}

// 优化 滑窗
vector<int> findAnagrams_Sw(string s, string p)
{
    vector<int> res;
    if (s.size() < p.size())
        return res;

    map<char, int> counter_map, sw_map;
    for (int j = 0; j < p.size(); j++)
        counter_map[p.at(j)]++;

    int start = 0, sw_len = p.size(), match_chars = sw_len;
    for (int i = 0; i < s.size(); i++)
    {
        if (i - start + 1 > sw_len)
        {
            sw_map[s.at(start)]--;

            if (sw_map[s.at(start)] <= 0)
                sw_map.erase(s.at(start));
            start++;
        }

        sw_map[s.at(i)]++;
        if (counter_map == sw_map)
            res.push_back(start);
    }
    return res;
}

// 还可以优化，比较两个map这里比较耗时
// 可以使用一个变量存储当前滑窗中有多少个字符 与 p 中未匹配上，当未匹配上数为0就是我们要找的结果

// 优化 滑窗
vector<int> findAnagrams_Sw_op(string s, string p)
{
    vector<int> res;
    if (s.size() < p.size())
        return res;

    // 存储子串中各个字符出现的次数
    map<char, int> need_match_counter;
    for (int j = 0; j < p.size(); j++)
        need_match_counter[p.at(j)]++;

    int start = 0, sw_len = p.size(), need_match = sw_len;
    for (int i = 0; i < s.size(); i++)
    {
        char m = s[i];
        // 如果这个字符在子串里存在: 待匹配的字符数-1
        // 如果sw是bba 但是 子串是abc 这种不应单单纯-1
        if (need_match_counter[m] >= 1)
            need_match--;
        // 将其在子串中出现的次数 - 1，避免出现 ab 匹配上aab
        need_match_counter[m]--;

        if (need_match == 0)
            res.push_back(start);

        // 窗口开始滑动
        if (i - start + 1 == sw_len)
        {
            // 划走的那个字符如果在子串：待匹配的字符+1
            if (need_match_counter[s[start]] >= 0)
                need_match++;
            // 如果这个串在子串里，子串移走了，其在子串出现次数加1
            need_match_counter[s[start]]++;
            start++;
        }
    }
    return res;
}

// 用字符数组代替map提高速度
vector<int> findAnagrams_Sw_op_Array(string s, string p)
{
    vector<int> res;
    if (s.size() < p.size())
        return res;

    // 存储子串中各个字符出现的次数; 用字符数组代替更快？
    // map<char, int> need_match_counter;
    int need_match_counter[256] = {0};
    for (int j = 0; j < p.size(); j++)
        need_match_counter[p.at(j)]++;

    int start = 0, sw_len = p.size(), need_match = sw_len;
    for (int i = 0; i < s.size(); i++)
    {
        char m = s[i];
        // 如果这个字符在子串里存在: 待匹配的字符数-1
        // 如果sw是bba 但是 子串是abc 这种不应单单纯-1
        if (need_match_counter[m] >= 1)
            need_match--;
        // 将其在子串中出现的次数 - 1，避免出现 ab 匹配上aab
        need_match_counter[m]--;

        if (need_match == 0)
            res.push_back(start);

        // 窗口开始滑动
        if (i - start + 1 == sw_len)
        {
            // 划走的那个字符如果在子串：待匹配的字符+1
            if (need_match_counter[s[start]] >= 0)
                need_match++;
            // 如果这个串在子串里，子串移走了，其在子串出现次数加1
            need_match_counter[s[start]]++;
            start++;
        }
    }
    return res;
}

vector<int> highVotes(string s, string p)
{
    vector<int> res = {};
    if (s.empty() || p.empty())
        return res;

    vector<int> hash(256, 0);
    for (auto c : p)
        hash[c]++;

    int sLen = s.size();
    int count = p.size();

    int left = 0;
    int right = 0;

    while (right < sLen)
    {
        if (hash[s[right]] >= 1)
            count--;

        hash[s[right]]--;
        right++;

        if (count == 0)
            res.push_back(left);

        if (right - left == p.size())
        {
            if (hash[s[left]] >= 0)
                count++;
            hash[s[left]]++;
            left++;
        }
    }
    return res;
}

int main()
{
    vector<int> s = findAnagrams_Sw("cbaebabacd", "abc");
    vector<int> s1 = findAnagrams_Sw_op("cbaebabacd", "abc");
    printVector(s);
    printVector(s1);
    printVector(highVotes("cbaebabacd", "abc"));
    printVector(findAnagrams_Sw_op_Array("cbaebabacd", "abc"));
}
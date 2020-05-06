#include "./com/header.h"
/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
*/

// Solution： 每次在谷底买入，然后在峰顶卖
int maxProfit(vector<int> &prices)
{
    int profit = 0, peak = 0, valley = 0, len = prices.size();
    for (int i(0); i < len; ++i)
    {

        while (i < len && prices[i] < prices[i + 1])
        {
            i++;
        }
        valley = prices[i];
        while (i < len && prices[i] > prices[i + 1])
        {
            i++;
        }
        peak = prices[i];
        profit += peak - valley;
    }
    return profit;
}

// 如果是1，2，3 : 3 - 1 = 2 - 1 + 3 - 2
int maxProfitOnePass(vector<int> &prices)
{
    int profit = 0;
    for (int i(1); i < prices.size(); ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

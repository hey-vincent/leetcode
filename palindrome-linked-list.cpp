#include "com/header.h"

/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

*/

// 这个是O（n）的空间复杂度
bool isPalindrome(ListNode *head)
{
    if (head == NULL)
        return false;
    ListNode *node = head;
    stack<int> nodes;
    int temp = head->val;
    while (node != NULL)
    {
        nodes.push(node->val);
        node = node->next;
    }
    node = head;
    while (node != NULL)
    {
        if (node->val != nodes.top())
            return false;
        nodes.pop();
        node = node->next;
    }
    return true;
}

// 另一种方案： 快慢指针，快指针一次两步，然后翻转左半部分再开始 从头部和中部判断
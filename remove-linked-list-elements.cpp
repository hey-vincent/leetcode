
#include <iostream>
#include <vector>
#include "./com/listnode.h"
using namespace std;

// https://leetcode.com/problems/remove-linked-list-elements/
// 删除list中指定元素
// typedef struct _ListNode
// {
//     int val;
//     _ListNode *next;
//     _ListNode(int x) : val(x), next(NULL) {}
// } ListNode;

// when you're not sure about how to do it. travel it at first

// 为什么不行？
ListNode *removeElements_Error_Result(ListNode *head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *p = head->next;
    ListNode *prev = head;
    while (p != NULL)
    {
        if (p->val == val)
        {
            prev->next = p->next;
        }
        prev = p;
        p = p->next;
    }
    if (head->val == val)
    {
        return head->next;
    }
    return head;
}

ListNode *removeElements_Fix(ListNode *head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    // x -> y -> z
    printListNode(head);
    ListNode *p = head->next;
    ListNode *prev = head;
    while (p != NULL)
    {
        ListNode *tmp = p->next;
        cout << "processing node " << p << endl;
        if (p->val == val)
        {
            prev->next = p->next;
        }
        else
        {
            prev = prev->next;
        }

        p = tmp;
    }

    printListNode(head);
    if (head->val == val)
    {
        head = head->next;
    }
    return head;
}

int main()
{
    int nums[] = {1, 1, 1};
    ListNode *head = composeListFrom(nums, sizeof(nums) / sizeof(int));
    // printListNode(head);
    // printListNode(head);
    printListNode(removeElements_Fix(head, 1));
}
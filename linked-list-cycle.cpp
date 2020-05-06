#include "com/header.h"

bool hasCycle(ListNode *head)
{
    map<ListNode *, bool> hash;
    ListNode *node = head;
    while (node != NULL)
    {
        if (hash.find(node) != hash.end())
            return true;
        hash[node] = true;
        node = node->next;
    }
    return false;
}

// 为什么这个死循环？
// case1: [1,2]，计算错误，因为对于一个无环链表，快指针走到末尾的时候就不走了，这时候慢指针仍往前走最终会相遇
bool hasCycleTwoPointers(ListNode *head)
{
    if (head == NULL)
        return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != NULL || fast != NULL)
    {
        // case1解决： 理论上，无环链表，快指针会先达到尾部
        if (fast != NULL && NULL == fast->next)
            return false;

        if (slow == fast)
            return true;

        if (slow != NULL)
            slow = slow->next;

        // if (fast != NULL) 这个会很慢，让快指针一次走两步快些
        if (fast != NULL && fast->next != NULL)
            fast = fast->next->next;
    }
    return false;
}

// 这是一个击败100%提交的答案，简洁至极！
// 我们的任务是找环，所以快指针一旦发现了 quick = NULL 或者 next = NULL 就证明无环了；
//  所以循环的时候可以精简, 循环的结束标志就是快指针达到尾部 + 快慢指针相遇
bool highVotesTwoPointers(ListNode *head)
{
    if (head == NULL)
        return false;
    ListNode *quick = head, *slow = head->next;
    while (quick != NULL && quick->next != NULL)
    {
        if (quick == slow)
            return true;
        quick = quick->next->next;
        slow = slow->next;
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 2, 7, 8};
    ListNode *list = composeListFrom(arr, 5);
    list->next->next->next->next->next = list->next;
    int i = 0;
    ListNode *p = list;
    while (i++ <= 4)
    {
        cout << p << "\t";
        p = p->next;
    }
    cout << endl
         << hasCycleTwoPointers(list);

    cout << endl
         << highVotesTwoPointers(list);
}
#include "com/header.h"
/*


Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


begin to intersect at node c1.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 

Example 2:


Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
 

Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.


*/

// 找两个链表的交汇点
// 普通做法 仍然可借助栈，交汇处就是 两个栈顶第一次不相等的时候的Next节点，但这个不是O（1）空间
// 或者使用Hash，但也不是O（1）空间
// 或者翻转两个链表，再判断

// 思路
// 1. 交汇是什么特征？如果节点i处交汇，意思是从i之后 所有节点指针都相等
// 2. 如果两个链表长度不一样，好像无法保证一次遍历达到交汇点。因为同时出发的时候，一个可能到达交汇点，但另一个还没到。
//

// 答案：
// O(N) Memory: HashTable
// O(1) Memory:
/*
Maintain two pointers pApA and pBpB initialized at the head of A and B, respectively.
 Then let them both traverse through the lists, one node at a time.
When pApA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); 
similarly when pBpB reaches the end of a list, redirect it the head of A.
If at any point pApA meets pBpB, then pApA/pBpB is the intersection node.
To see why the above trick would work, 
    consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. 
    Since B.length (=4) < A.length (=6), 
    pBpB would reach the end of the merged list first, 
    because pBpB traverses exactly 2 nodes less than pApA does. 
    By redirecting pBpB to head A, and pApA to head B, we now ask pBpB to travel exactly 2 more nodes than pApA would. So in the second iteration, 
    they are guaranteed to reach the intersection node at the same time.
If two lists have intersection, then their last nodes must be the same one. 
So when pApA/pBpB reaches the end of a list, record the last element of A/B respectively. 
If the two last elements are not the same one, then the two lists have no intersections.
*/

ListNode *reverse(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *new_head = head;
    ListNode *node = head->next;
    head->next = NULL;

    while (node != NULL)
    {
        ListNode *p = node->next;
        node->next = new_head;
        new_head = node;
        node = p;
    }
    return new_head;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    headA = reverse(headA);
    headB = reverse(headB);
    if (headA != headB)
        return NULL;
    ListNode *node = NULL;
    while (headA != NULL || headB != NULL)
    {
        if (headA && headB)
        {
            if (headA != headB)
                return node;
            else
                node = headA;
        }

        if (headA != NULL)
            headA = headA->next;

        if (headB != NULL)
            headB = headB->next;
    }
    return node;
}

int main()
{
    int arr[] = {2, 3, 4, 9, 1};
    ListNode *p = composeListFrom(arr, 5);
    p = reverse(p);
    printListNode(p);
}
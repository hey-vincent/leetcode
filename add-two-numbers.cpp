#include <iostream>
using namespace std;

// https://leetcode.com/problems/add-two-numbers/
// 题本身不难 只是在处理的时候需要注意 循环之后 是否还需要进位
// 增加一个 虚拟头结点能比较方便的处理

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *head = new ListNode(INT_MIN);
  ListNode *tail = head;
  int carry = 0;

  while (l1 || l2) {
    int sum = carry;
    if (l1 != NULL) {
      sum += l1->val;
      l1 = l1->next;
    }

    if (l2 != NULL) {
      sum += l2->val;
      l2 = l2->next;
    }

    ListNode *node = new ListNode(sum % 10);
    carry = sum / 10;

    tail->next = node;
    tail = node;
  }

  if (carry != 0) {
    tail->next = new ListNode(carry);
  }

  return head->next;
}

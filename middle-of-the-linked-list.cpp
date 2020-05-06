#include "./com/header.h"

// Find the middle of a linked list
//
//

// Solution 1: output into an array
ListNode *middleNode(ListNode *head)
{
	if (head == NULL)
		return NULL;
	ListNode *node = head;
	vector<ListNode *> nodes_arr;
	while (node != NULL)
	{
		nodes_arr.push_back(node);
		node = node->next;
	}

	return nodes_arr[nodes_arr.size() / 2];
}

// Solution 2: 快慢指针
ListNode *middleOfList(ListNode *head)
{
	ListNode *slow = head, *fast = head;
	while (slow != NULL && fast != NULL)
	{
		slow = slow->next;
		if (NULL == fast->next)
			break;
		fast = fast->next->next;
	}
	return slow;
}

int main()
{
	vector<int> nodes{1, 3, 5, 7, 9, 11};
	ListNode *list = composeListFrom(nodes);
	printListNode(list);
	printListNode(middleOfList(list));
}
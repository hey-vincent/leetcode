#include <iostream>
#include <vector>
using namespace std;

typedef struct _ListNode
{
    int val;
    _ListNode *next;
    _ListNode(int x) : val(x), next(NULL) {}
} ListNode;

ListNode *composeListFrom(int arr[], int length)
{
    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < length; i++)
    {
        ListNode *node = new ListNode(arr[i]);
        if (head == NULL)
        {
            head = node;
            tail = head;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
    }

    return head;
}

ListNode *composeListFrom(vector<int> &source)
{
    ListNode *head = NULL, *tail = NULL;
    vector<int>::iterator it = source.begin();
    while (it != source.end())
    {
        if (it == source.begin())
        {
            head = new ListNode(*it);
            tail = head;
            tail->next = NULL;
        }
        else
        {
            ListNode *node = new ListNode(*it);
            tail->next = node;
            tail = node;
        }
        it++;
    }
    return head;
}

void printListNode(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << "[" << head << "]:next(" << head->next << ")\t";
        head = head->next;
    }
    cout << endl;
}
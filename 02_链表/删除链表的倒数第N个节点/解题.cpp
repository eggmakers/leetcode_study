// 给你一个链表，删除链表的倒数第n个结点，并且返回链表的头结点。
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead;
        while (n-- && fast != NULL)
        {
            fast = fast->next;
        }
        fast = fast->next;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};

int main() // 没懂怎么定义链表
{
    ListNode *l6 = new ListNode(6);
    ListNode *l5 = new ListNode(5, l6);
    ListNode *l4 = new ListNode(4, l5);
    ListNode *l3 = new ListNode(3, l4);
    ListNode *l2 = new ListNode(2, l3);
    ListNode *l1 = new ListNode(1, l2);

    Solution so;
    cout << so.removeNthFromEnd(l1, 3)->val << " "
         << so.removeNthFromEnd(l1, 3)->next->val << " "
         << so.removeNthFromEnd(l1, 3)->next->next->val << " "
         << so.removeNthFromEnd(l1, 3)->next->next->next->val << " "
         << so.removeNthFromEnd(l1, 3)->next->next->next->next->val << " "
         << so.removeNthFromEnd(l1, 3)->next->next->next->next->next->val << " " << endl;
}
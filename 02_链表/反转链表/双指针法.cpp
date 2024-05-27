// 题意：反转一个单链表。
// 示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct ListNode1
{
    int val;
    ListNode1 *next;
    ListNode1(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode1 *reverseList(ListNode1 *head)
    {
        ListNode1 *tmp;
        ListNode1 *cur = head;
        ListNode1 *pre = NULL;
        while (cur)
        {
            tmp = cur->next;
            cur->next = pre;

            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main()
{
    ListNode1 *l6 = new ListNode1(6);
    ListNode1 *l5 = new ListNode1(5);
    ListNode1 *l4 = new ListNode1(4);
    ListNode1 *l3 = new ListNode1(3);
    ListNode1 *l2 = new ListNode1(2);
    ListNode1 *l1 = new ListNode1(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;

    Solution so;
    cout << so.reverseList(l1)->val << " "
         << so.reverseList(l1)->next->val << " "
         << so.reverseList(l1)->next->next->val << " "
         << so.reverseList(l1)->next->next->next->val << " "
         << so.reverseList(l1)->next->next->next->next->val << " "
         << so.reverseList(l1)->next->next->next->next->next->val << " " << endl;
}
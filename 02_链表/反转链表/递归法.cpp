// 题意：反转一个单链表。
// 示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct ListNode2
{
    int val;
    ListNode2 *next;
    ListNode2(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode2 *reverse(ListNode2 *pre, ListNode2 *cur)
    {
        if (cur == NULL)
            return pre;
        ListNode2 *tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
    ListNode2 *reverseList(ListNode2 *head)
    {
        return reverse(NULL, head);
    }
};

int main()
{
    ListNode2 *l6 = new ListNode2(6);
    ListNode2 *l5 = new ListNode2(5);
    ListNode2 *l4 = new ListNode2(4);
    ListNode2 *l3 = new ListNode2(3);
    ListNode2 *l2 = new ListNode2(2);
    ListNode2 *l1 = new ListNode2(1);
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
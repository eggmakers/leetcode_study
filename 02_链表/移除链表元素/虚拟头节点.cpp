// 删除链表中等于给定值 val 的所有节点。
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
                cur = cur->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
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
    cout << so.removeElements(l1, 3)->val << " "
         << so.removeElements(l1, 3)->next->val << " "
         << so.removeElements(l1, 3)->next->next->val << " "
         << so.removeElements(l1, 3)->next->next->next->val << " "
         << so.removeElements(l1, 3)->next->next->next->next->val << " "
         << so.removeElements(l1, 3)->next->next->next->next->next->val << " " << endl;
}
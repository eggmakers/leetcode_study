// 题意： 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
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
    l6->next = l3;

    Solution so;
    cout << so.detectCycle(l1)->val << endl;
}
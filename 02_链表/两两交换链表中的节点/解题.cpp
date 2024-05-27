#include <iostream>
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
    ListNode *swapPairs(ListNode *head)
    {
        // 创建一个虚拟头结点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;

        // 遍历链表，进行两两交换
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *first = cur->next;
            ListNode *second = cur->next->next;
            ListNode *nextPair = cur->next->next->next;

            // 交换节点
            cur->next = second;
            second->next = first;
            first->next = nextPair;

            // 移动到下一个要交换的节点
            cur = first;
        }

        // 获取交换后的头节点
        ListNode *result = dummyHead->next;

        // 打印结果链表
        ListNode *cur1 = result;
        while (cur1 != nullptr)
        {
            cout << cur1->val << " ";
            cur1 = cur1->next;
        }
        cout << endl;

        // 释放虚拟头节点的内存
        delete dummyHead;

        return result;
    }
};

int main()
{
    // 创建链表 1->2->3->4->5->6
    ListNode *l6 = new ListNode(6);
    ListNode *l5 = new ListNode(5, l6);
    ListNode *l4 = new ListNode(4, l5);
    ListNode *l3 = new ListNode(3, l4);
    ListNode *l2 = new ListNode(2, l3);
    ListNode *l1 = new ListNode(1, l2);

    Solution so;
    ListNode *result = so.swapPairs(l1);

    // 打印交换后的链表
    ListNode *cur = result;
    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 释放链表内存
    while (result != nullptr)
    {
        ListNode *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}

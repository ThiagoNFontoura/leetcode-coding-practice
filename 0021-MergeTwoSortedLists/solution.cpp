#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
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
    ListNode *transferNode(ListNode *giver, ListNode *receiver)
    {
        ListNode *temp, *remGiv;

        remGiv = giver->next;
        temp = receiver->next;

        receiver->next = giver;
        giver->next = temp;

        return remGiv;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head, *temp, *prev1 = nullptr;

        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        head = list1;

        if (list1->val > list2->val) // inicializa prev1
        {
            head = list2;
            temp = list2->next;
            prev1 = list2;
            list2->next = list1;
            list2 = temp;
        }

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                prev1 = list1;
                list1 = list1->next;
            }
            else
            {
                list2 = transferNode(list2, prev1);
                prev1 = prev1->next;
            }
        }

        if (list1 == nullptr)
            prev1->next = list2;

        return head;
    }
};
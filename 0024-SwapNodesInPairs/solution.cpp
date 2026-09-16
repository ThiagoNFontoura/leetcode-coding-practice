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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *first, *second, *temp, *prev;

        prev = head;
        first = head;
        head = head->next;

        while (true)
        {
            if (first == nullptr || first->next == nullptr)
                return head;

            second = first->next;
            temp = second->next;

            prev->next = second;
            second->next = first;
            first->next = temp;

            prev = first;
            first = temp;
        }
    }
};
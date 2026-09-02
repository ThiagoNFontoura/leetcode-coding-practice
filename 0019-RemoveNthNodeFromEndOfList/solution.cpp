#include <bits/stdc++.h>

using namespace std;

//  Definition for singly-linked list.
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
        if (head == nullptr)
            return head;

        ListNode *scanner = head;
        vector<ListNode *> h;

        while (scanner != nullptr)
        {
            h.push_back(scanner);
            scanner = scanner->next;
        }

        int m = h.size();

        if (m < n)
            return head;

        if (n == 1)
        {
            if (m == 1)
            {
                delete head;
                return nullptr;
            }

            h[m - 2]->next = nullptr;
            delete h[m - 1];
            return head;
        }

        int realPos = m - n;

        if (realPos == 0)
        {
            head = h[1];
            delete h[0];
            return head;
        }

        h[realPos - 1]->next = h[realPos + 1];
        delete h[realPos];

        return head;
    }
};
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

    struct CompareNode
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, CompareNode> pq;

        for (ListNode *vln : lists)
            if (vln != nullptr)
                pq.push(vln);

        if (pq.empty())
            return nullptr;

        ListNode *head = pq.top();
        ListNode *temp = head;
        pq.pop();
        if (head->next != nullptr)
            pq.push(head->next);

        if (pq.empty())
            return head;

        while (!pq.empty())
        {
            temp->next = pq.top();
            temp = temp->next;
            pq.pop();

            if (temp->next != nullptr)
                pq.push(temp->next);
        }

        return head;
    }
};
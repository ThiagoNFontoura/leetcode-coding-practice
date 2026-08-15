
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return solve(l1, l2);
    }

    ListNode *solve(ListNode *l1 = nullptr, ListNode *l2 = nullptr, int cin = 0)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            if (cin != 0)
                return new ListNode(cin);
            return nullptr;
        }
        if (l1 == nullptr)
        {
            int val = l2->val + cin;
            int cout = val / 10;
            val %= 10;

            return new ListNode(val, solve(l1, l2->next, cout));
        }
        if (l2 == nullptr)
        {
            int val = l1->val + cin;
            int cout = val / 10;
            val %= 10;

            return new ListNode(val, solve(l1->next, l2, cout));
        }

        int val = l1->val + l2->val + cin;
        int cout = val / 10;
        val %= 10;

        return new ListNode(val, solve(l1->next, l2->next, cout));
    }
};
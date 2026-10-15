#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int s = nums.size();
        unordered_map<int, int> m;
        int c = 0;
        int sum = 0;

        for (int i = 0; i < s; i++)
        {
            for (int j = i; j < s; j++)
            {
                auto &p = m[nums[j]];
                p++;

                if (p == 1)
                    c++;

                sum += c * c;
            }
            c = 0;
            m.clear();
        }

        return sum;
    }
};
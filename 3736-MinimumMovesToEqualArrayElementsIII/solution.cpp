#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int m = 0;
        int s = 0;
        for (int n : nums)
        {
            s += n;
            if (m < n)
                m = n;
        }

        return m * nums.size() - s;
    }
};
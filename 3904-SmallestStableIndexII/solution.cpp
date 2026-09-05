#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        vector<int> minN;
        vector<int> maxN;

        int n = nums.size();

        int temp = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (temp < nums[i])
                temp = nums[i];
            maxN.push_back(temp);
        }

        temp = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            if (temp > nums[i])
                temp = nums[i];
            minN.push_back(temp);
        }

        for (int i = 0; i < n; i++)
        {
            temp = maxN[i] - minN[n - 1 - i];
            if (temp <= k)
                return i;
        }

        return -1;
    }
};
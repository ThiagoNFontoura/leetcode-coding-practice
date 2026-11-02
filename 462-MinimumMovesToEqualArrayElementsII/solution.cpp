#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int m = nums[nums.size() / 2];
        int s = 0;

        for (int n : nums)
            s += abs(n - m);

        return s;
    }
};
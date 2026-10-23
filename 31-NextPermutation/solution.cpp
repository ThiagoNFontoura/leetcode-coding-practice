#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int s = nums.size(), i = s - 1;

        if (s < 2)
            return;
        if (s == 2)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        while (i > 0 && nums[i] <= nums[i - 1])
            i--;
        i--;

        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int min = INT32_MAX;
        int p = i;

        for (int j = i + 1; j < s; j++)
            if (nums[j] > nums[i] && nums[j] < min)
            {
                min = nums[j];
                p = j;
            }

        swap(nums[i], nums[p]);

        sort(nums.begin() + i + 1, nums.end());
    }
};
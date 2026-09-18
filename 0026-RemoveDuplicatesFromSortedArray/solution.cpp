#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int s = nums.size();
        auto b = nums.begin();

        if (s == 0 || s == 1)
            return s;

        int j = 1;

        for (int i = 1; i < s; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};
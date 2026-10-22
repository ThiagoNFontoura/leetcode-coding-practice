#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int nSize = nums.size();

        if (nSize < 2)
            return 0;
        if (nSize == 2)
        {
            if (nums[0] < nums[1])
                return 0;
            return 1;
        }

        int asc = 0;
        int desc = 0;

        for (int i = 0; i < nSize; i++)
        {
            int j = (i + 1 == nSize) ? 0 : i + 1;

            if (nums[i] < nums[j])
                asc++;
            else
                desc++;
        }

        int breakP = -1;

        if (asc > desc)
        {
            for (int i = 0; i < nSize; i++)
            {
                int j = (i + 1 == nSize) ? 0 : i + 1;

                if (nums[i] < nums[j])
                {
                    if (nums[j] != nums[i] + 1)
                        return -1;
                }
                else
                {
                    if (breakP != -1)
                        return -1;
                    breakP = j;
                }
            }
        }
        else
        {
            for (int i = 0; i < nSize; i++)
            {
                int j = (i + 1 == nSize) ? 0 : i + 1;

                if (nums[i] > nums[j])
                {
                    if (nums[j] != nums[i] - 1)
                        return -1;
                }
                else
                {
                    if (breakP != -1)
                        return -1;
                    breakP = j;
                }
            }
        }

        return (asc > desc) ? min(breakP, nSize - breakP + 2) : min(breakP, nSize - breakP) + 1;
    }
};
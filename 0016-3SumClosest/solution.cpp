#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int sol = INT_MAX;
        int diffSol = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if (abs(target - sum) < diffSol)
                {
                    sol = sum;
                    diffSol = abs(target - sum);
                }

                if (target < sum)
                    r--;
                else if (target > sum)
                    l++;
                else
                    return sum;
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1])
                i++;
        }

        return sol;
    }
};
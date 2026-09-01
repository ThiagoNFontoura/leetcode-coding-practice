#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> sol;

        int n = nums.size();
        if (n < 4)
            return sol;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = n - 1; j > i + 2; j--)
            {
                if (j < n - 1 && nums[j] == nums[j + 1])
                    continue;

                int l = i + 1, r = j - 1;

                while (l < r)
                {
                    long long sum = (long long)nums[i] + nums[l] + nums[r] + nums[j];

                    if (sum < target)
                        l++;
                    else if (sum > target)
                        r--;
                    else
                    {
                        sol.push_back({nums[i], nums[l], nums[r], nums[j]});

                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        l++;
                        while (l < r && nums[r] == nums[r - 1])
                            r--;
                        r--;
                    }
                }
            }
        }

        return sol;
    }
};
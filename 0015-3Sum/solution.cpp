#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> sol;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if (0 < sum)
                    r--;
                else if (sum < 0)
                    l++;
                else
                {
                    sol.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    l++;

                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    r--;
                }
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1])
                i++;
        }

        return sol;
    }
};
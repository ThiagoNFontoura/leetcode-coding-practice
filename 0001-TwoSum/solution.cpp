#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> algorithm;
        for (int n : nums)
            algorithm.push_back(n);
        sort(algorithm.begin(), algorithm.end());

        int i = -1;
        int j = -1;

        while (j == -1)
        {
            i++;
            int start = i + 1;
            int end = algorithm.size() - 1;
            int complement = target - algorithm[i];

            while (true)
            {
                int mid = (start + end) / 2;

                if (complement == algorithm[mid]) // complement exists
                {
                    j = mid;
                    break;
                }
                if (start >= end) // complement does not exist
                    break;

                if (complement < algorithm[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }

        vector<int> solution;
        int a = algorithm[i];
        int b = algorithm[j];

        for (int n = 0; n < nums.size(); n++)
            if ((a == nums[n] || b == nums[n]) && solution.size() < 2)
                solution.push_back(n);

        return solution;
    }
};
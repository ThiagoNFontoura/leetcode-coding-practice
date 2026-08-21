#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int maxA = 0;

        while (l < r)
        {
            int w = r - l;
            int a = w * min(height[l], height[r]);
            maxA = max(maxA, a);
            if (height[r] < height[l])
                r--;
            else
                l++;
        }

        return maxA;
    }
};
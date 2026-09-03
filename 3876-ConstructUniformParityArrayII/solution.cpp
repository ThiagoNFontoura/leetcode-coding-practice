#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int n : nums1)
            if (n % 2 == 1)
            {
                if (n < minOdd)
                    minOdd = n;
            }
            else if (n < minEven)
                minEven = n;

        if (minOdd == INT_MAX)
            return true;
        if (minOdd < minEven)
            return true;
        return false;
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        vector<int> small = nums1, big = nums2;
        if (n < m)
        {
            int temp = m;
            m = n;
            n = temp;
            big = nums1;
            small = nums2;
        }

        int start = 0, end = m;
        int i = (start + end) / 2, j = (m + n + 1) / 2 - i;
        int L1 = INT_MIN, R1 = INT_MAX, L2 = INT_MIN, R2 = INT_MAX;

        if (i > 0)
            L1 = small[i - 1];
        if (i < m)
            R1 = small[i];
        if (j > 0)
            L2 = big[j - 1];
        if (j < n)
            R2 = big[j];

        while (L1 > R2 || L2 > R1)
        {
            if (L1 > R2)
                end = i - 1;
            else if (L2 > R1)
                start = i + 1;

            i = (start + end) / 2;
            j = (m + n + 1) / 2 - i;

            L1 = INT_MIN;
            R1 = INT_MAX;
            L2 = INT_MIN;
            R2 = INT_MAX;

            if (i > 0)
                L1 = small[i - 1];
            if (i < m)
                R1 = small[i];
            if (j > 0)
                L2 = big[j - 1];
            if (j < n)
                R2 = big[j];
        }

        if ((m + n) % 2 == 1)
            return max(L1, L2);
        else
            return (max(L1, L2) + min(R1, R2)) / 2.0;
    }
};
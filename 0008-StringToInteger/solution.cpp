#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int pos = 0;
        while (s[pos] == ' ')
            pos++;

        long long solution = 0;
        bool isNegative = false;

        if (s[pos] == '-')
        {
            isNegative = true;
            pos++;
        }
        else if (s[pos] == '+')
            pos++;
        if (s[pos] < '0' || s[pos] > '9')
            return 0;

        while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9')
        {
            int temp = s[pos] - '0';
            solution *= 10;
            solution += temp;
            pos++;

            if (solution > INT_MAX)
            {
                if (isNegative)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }

        if (isNegative)
            return -1 * solution;
        return solution;
    }
};
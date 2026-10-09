#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        bool neg = false;

        if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0))
            neg = true;

        unsigned int udivisor = abs((long long)divisor);
        unsigned int udividend = abs((long long)dividend);

        if (udivisor > udividend)
            return 0;

        unsigned int res = 0;

        if (udivisor != udividend)
        {

            unsigned long long sub = udivisor;

            while (sub <= udividend)
            {
                unsigned long long temp = 1ULL;
                while (sub <= udividend)
                {
                    sub = sub << 1;
                    temp = temp << 1;
                }

                udividend -= sub >> 1;
                res += temp >> 1;
                sub = udivisor;
            }
        }
        else
            res = 1;

        unsigned int limit = 1U << 31;

        if (neg)
        {
            if (res > limit)
                return -limit;
            return -res;
        }

        if (res > limit - 1)
            return limit - 1;
        return res;
    }
};
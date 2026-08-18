#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long int reverse = 0;

        while (x != 0)
        {
            int temp = x % 10;
            x /= 10;

            reverse *= 10;
            reverse += temp;
        }

        if (reverse > INT_MAX || reverse < INT_MIN)
            return 0;
        return (int)reverse;
    }
};
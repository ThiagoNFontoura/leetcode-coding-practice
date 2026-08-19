#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        long long rev = 0, temp = x;

        while (temp != 0)
        {
            rev *= 10;
            rev += temp % 10;
            temp /= 10;
        }

        if (rev == x)
            return true;
        return false;
    }
};
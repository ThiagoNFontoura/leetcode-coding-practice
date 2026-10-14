#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        if (sum > num * 9)
            return "";

        string res;
        res.reserve(num);

        res.append(sum / 9, '9');
        sum %= 9;

        if (sum != 0)
            res.append(1, '0' + sum);

        res.append(num - res.size(), '0');

        return res;
    }
};
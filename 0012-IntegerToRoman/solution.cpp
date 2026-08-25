#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> v = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> r = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string sol = "";

        for (int i = 0; i < v.size(); i++)
        {
            while (num >= v[i])
            {
                num -= v[i];
                sol += r[i];
            }
        }

        return sol;
    }
};
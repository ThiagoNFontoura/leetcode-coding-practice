#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        string sol = "";

        for (int i = 0; i < 201; i++)
        {

            char c = strs[0][i];

            for (int j = 0; j < strs.size(); j++)
                if (strs[j].length() == i || strs[j][i] != c)
                    return sol;

            sol += c;
        }

        return sol;
    }
};
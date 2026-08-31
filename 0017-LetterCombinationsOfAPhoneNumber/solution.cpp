#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_map<char, vector<string>> keyb;

    vector<string> letterCombinations(string digits)
    {
        keyb['2'] = {"a", "b", "c"};
        keyb['3'] = {"d", "e", "f"};
        keyb['4'] = {"g", "h", "i"};
        keyb['5'] = {"j", "k", "l"};
        keyb['6'] = {"m", "n", "o"};
        keyb['7'] = {"p", "q", "r", "s"};
        keyb['8'] = {"t", "u", "v"};
        keyb['9'] = {"w", "x", "y", "z"};

        return solve(digits);
    }

    vector<string> solve(string digits)
    {
        if (digits.length() == 1)
            return keyb[digits[0]];

        vector<string> sol;
        vector<string> temp = solve(digits.substr(1));

        for (string s0 : keyb[digits[0]])
            for (string s1 : temp)
                sol.push_back(s0 + s1);

        return sol;
    }
};
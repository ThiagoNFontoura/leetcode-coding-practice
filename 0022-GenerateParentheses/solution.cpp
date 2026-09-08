#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<vector<string>>> M(n + 1, vector<vector<string>>(n + 1));

        return solve(M, n, 0);
    }

    vector<string> solve(vector<vector<vector<string>>> &M, int n, int m)
    {
        if (n == 0 && m == 0)
            return {""};

        if (!M[n][m].empty())
            return M[n][m];

        vector<string> sol;
        if (n != 0)
        {
            vector<string> openPar = solve(M, n - 1, m + 1);
            for (string s : openPar)
                sol.push_back('(' + s);
        }
        if (m != 0)
        {
            vector<string> closePar = solve(M, n, m - 1);
            for (string s : closePar)
                sol.push_back(')' + s);
        }

        M[n][m] = sol;
        return sol;
    }
};
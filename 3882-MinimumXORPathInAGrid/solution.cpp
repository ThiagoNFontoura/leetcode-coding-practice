#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> b(m, vector<bitset<1024>>(n));

        b[0][0][grid[0][0]] = 1;

        for (int i = 1; i < n; i++)
            for (int j = 0; j < 1024; j++)
                if (b[0][i - 1][j])
                    b[0][i][j ^ grid[0][i]] = 1;

        for (int i = 1; i < m; i++)
            for (int j = 0; j < 1024; j++)
                if (b[i - 1][0][j])
                    b[i][0][j ^ grid[i][0]] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                for (int k = 0; k < 1024; k++)
                {
                    if (b[i][j - 1][k])
                        b[i][j][k ^ grid[i][j]] = 1;
                    if (b[i - 1][j][k])
                        b[i][j][k ^ grid[i][j]] = 1;
                }
            }
        }

        for (int i = 0; i < 1024; i++)
            if (b[m - 1][n - 1][i])
                return i;

        return -1;
    }
};
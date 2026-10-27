#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> createGrid(int m, int n)
    {
        string s0(n, '.'), s1(n, '#');
        s1[n - 1] = '.';

        vector<string> g;
        g.push_back(s0);

        for (int i = 1; i < m; i++)
            g.push_back(s1);

        return g;
    }
};
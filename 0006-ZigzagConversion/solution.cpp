#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string lines[numRows];
        for (int i = 0; i < numRows; i++)
            lines[i] = "";

        int pos = 0;
        bool isGoingUp = false;

        for (char c : s)
        {
            if (!isGoingUp)
            {
                lines[pos] += c;
                pos++;
                if (pos == numRows)
                {
                    pos -= 2;
                    if (pos != 0)
                        isGoingUp = true;
                }
            }
            else
            {
                lines[pos] += c;
                pos--;
                if (pos == 0)
                    isGoingUp = false;
            }
        }

        string solution = "";

        for (string s : lines)
            solution += s;

        return solution;
    }
};
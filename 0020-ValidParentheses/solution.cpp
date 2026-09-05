#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else
            {
                if (stk.empty())
                    return false;
                char cStk = stk.top();
                stk.pop();
                switch (c)
                {
                case ')':
                    if (cStk != '(')
                        return false;
                    break;
                case ']':
                    if (cStk != '[')
                        return false;
                    break;
                case '}':
                    if (cStk != '{')
                        return false;
                    break;
                default:
                }
            }
        }
        return stk.empty();
    }
};
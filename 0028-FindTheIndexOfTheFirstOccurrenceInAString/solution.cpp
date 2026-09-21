#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = needle.size();
        int limit = haystack.size() - n + 1;

        for (int i = 0; i < limit; i++)
        {
            if (haystack[i] == needle[0])
            {
                bool found = true;

                for (int j = 0; j < n; j++)
                    if (haystack[i + j] != needle[j])
                    {
                        found = false;
                        break;
                    }

                if (found)
                    return i;
            }
        }
        return -1;
    }
};
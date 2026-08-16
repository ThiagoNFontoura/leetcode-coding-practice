#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> chars;
        int maxL, left, right = left = maxL = 0;

        for (; right < s.size(); right++)
        {
            char c = s[right];

            if (chars.count(c) != 0 && chars[c] >= left)
                left = chars[c] + 1;

            chars[c] = right;
            maxL = max(maxL, right - left + 1);
        }

        return maxL;
    }
};
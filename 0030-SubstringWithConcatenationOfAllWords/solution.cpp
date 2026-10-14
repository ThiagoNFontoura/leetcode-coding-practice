#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> all, seen;
        vector<int> res;

        int strSize = words[0].size();
        int wSize = words.size();
        int n = s.size();

        for (int i = 0; i < wSize; i++)
            all[words[i]]++;

        for (int off = 0; off < strSize; off++)
        {
            int l = off, count = 0;

            for (int r = off; r + strSize <= n; r += strSize)
            {
                string temp = s.substr(r, strSize);

                auto it = all.find(temp);
                if (it == all.end())
                {
                    seen.clear();
                    count = 0;
                    l = r + strSize;
                    continue;
                }

                seen[temp]++;
                count++;

                while (seen[temp] > it->second)
                {
                    seen[s.substr(l, strSize)]--;
                    count--;
                    l += strSize;
                }

                if (count == wSize)
                {
                    res.push_back(l);
                    seen[s.substr(l, strSize)]--;
                    count--;
                    l += strSize;
                }
            }
            seen.clear();
        }

        return res;
    }
};
using namespace std;

class Solution
{
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        if (costBoth < cost1 + cost2)
        {
            long long r = (long long)costBoth * (need1 < need2 ? need1 : need2);

            if (need1 != need2)
            {
                if (need1 < need2)
                    return r + (long long)(need1 < need2 ? need2 - need1 : need1 - need2) * (cost2 < costBoth ? cost2 : costBoth);
                if (need2 < need1)
                    return r + (long long)(need1 < need2 ? need2 - need1 : need1 - need2) * (cost1 < costBoth ? cost1 : costBoth);
            }

            return r;
        }

        long long r = (long long)(cost1 + cost2) * (need1 < need2 ? need1 : need2);

        if (need1 != need2)
        {
            if (need1 < need2)
                return r + (long long)(need1 < need2 ? need2 - need1 : need1 - need2) * cost2;
            if (need2 < need1)
                return r + (long long)(need1 < need2 ? need2 - need1 : need1 - need2) * cost1;
        }

        return r;
    }
};
#include "../../headers.h"

class Solution
{
public:
    long long minimumTotalCost(vector<int> &a, vector<int> &b)
    {
        long long ans = 0;
        int cnt = 0, num = -1, eq = 0;
        unordered_map<int, int> ump;

        for(int i = 0; i < a.size(); i++)
            if(a[i] == b[i])
            {
                ans += i;
                ump[a[i]]++;
                if(ump[a[i]] > cnt)
                    cnt = ump[a[i]], num = a[i];
                eq++;
            }

        if(cnt <= eq / 2)
            return ans;

        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i] && a[i] != num && b[i] != num)
            {
                ump[a[i]]++;
                eq++;
                ans += i;
                if(cnt <= eq / 2)
                    return ans;
            }
        }
        return -1;
    }
};
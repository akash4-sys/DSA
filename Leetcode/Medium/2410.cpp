#include "headers.h"

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &p, vector<int> &t)
    {
        sort(p.begin(), p.end());
        int l = 0, r = min(p.size(), t.size());

        while(l < r) 
        {
            int m = (l + r + 1) / 2;
            bool flag = true;
            multiset<int> ms(t.begin(), t.end());

            for (int i = m - 1; i >= 0; i--)
            {
                auto it = prev(end(ms));
                   if(p[i] <= *it)
                    ms.erase(it);
                else
                {
                    auto it = ms.lower_bound(p[i] );
                    if(it != ms.end())
                        ms.erase(it);
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            (flag) ? l = m : r = m - 1;
        }

        return l;
    }
};



class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &pla, vector<int> &t)
    {
        vector<int> vis(t.size(), 0);
        int ans = 0, rem = t.size();
        sort(pla.begin(), pla.end());
        sort(t.begin(), t.end());
        for(int p: pla)
        {
            if(rem == 0)
                return ans;
            for(int i = 0; i < t.size(); i++)
            {
                if(!vis[i] && p <= t[i])
                {
                    ans++; 
                    rem--; 
                    vis[i] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
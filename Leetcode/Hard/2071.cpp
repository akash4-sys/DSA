#include "../../headers.h"

class Solution
{
public:
    int maxTaskAssign(vector<int> &t, vector<int> &w, int pills, int strength)
    {
        sort(t.begin(), t.end());
        int l = 0, r = min(t.size(), w.size());

        while (l < r)
        {
            int m = (l + r + 1) / 2, need = 0;
            bool flag = true;
            multiset<int> ms(w.begin(), w.end());

            for (int i = m - 1; i >= 0; i--)
            {
                auto it = prev(end(ms));
                if(t[i] <= *it)
                    ms.erase(it);
                else
                {
                    auto it = ms.lower_bound(t[i] - strength);
                    if(it != ms.end() && need++ < pills)
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
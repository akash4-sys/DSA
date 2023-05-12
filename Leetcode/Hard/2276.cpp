#include "../../headers.h"

class CountIntervals
{
    map<int, int> mp;
    int cnt = 0;
    
public:
    void add(int l, int r)
    {
        auto it = mp.upper_bound(l);
        if (it != begin(mp) && prev(it)->second >= l)
            it--;

        for (; it != end(mp) && it->first <= r; it = mp.erase(it))
        {
            l = min(l, it->first);
            r = max(r, it->second);
            cnt -= (it->second - it->first + 1);
        }
        cnt += (r - l + 1);
        mp[l] = r; 
    }

    int count()
    {
        return cnt;
    }
};
#include "../../headers.h"

class MyCalendarTwo 
{
    map<int, int> mp;
public:
    bool book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        int cnt = 0;
        for(auto [t, c]: mp)
        {
            cnt += c;
            if(cnt == 3)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};
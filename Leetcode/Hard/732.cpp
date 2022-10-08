#include "../../headers.h"

class MyCalendarThree
{
    map<int, int> mp;
public:
    MyCalendarThree(){}
    int book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        int mx = 0, cnt = 0;
        for(auto [t, c]: mp)
            cnt += c, mx = max(mx, cnt);
        return mx;
    }
};
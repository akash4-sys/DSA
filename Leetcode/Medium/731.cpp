#include "../../headers.h"

class MyCalendarTwo
{
    map<int, int> mp;
public:
    MyCalendarTwo(){}
    bool book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        int booked = 0;
        for(auto [time, cnt]: mp)
        {
            booked += cnt;
            if(booked == 3)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};
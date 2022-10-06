#include "../../headers.h"

class TimeMap
{
    unordered_map<int, pair<string, string>> time_map;
public:
    TimeMap()
    {
        time_map = unordered_map<int, pair<string, string>>();
    }

    void set(string key, string value, int time)
    {
        time_map[time] = {key, value};
    }

    string get(string key, int timestamp)
    {
        while (timestamp)
            if (time_map.count(timestamp) && time_map[timestamp].first == key)
                return time_map[timestamp].second;
            else
                timestamp--;
        return "";
    }
};

// @lc app=leetcode id=981 lang=cpp
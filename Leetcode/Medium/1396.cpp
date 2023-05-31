#include "../../headers.h"

class UndergroundSystem
{
    unordered_map<string, pair<double, double>> trips;
    unordered_map<int, pair<string, int>> mp;

public:
    void checkIn(int id, string stationName, int t)
    {
        mp[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto [checkInStation, st] = mp[id];
        string key = checkInStation + "->" + stationName;
        trips[key].first += (t - st);
        trips[key].second++;
        mp.erase(id);
    }

    double getAverageTime(string startStation, string endStation)
    {
        auto [time, n] = trips[startStation + "->" + endStation];
        return time / n;
    }
};
#include "headers.h"

class FrequencyTracker
{
    int cnt[100001] = {0}, freq[100001] = {0};
public:
    void add(int n)
    {
        freq[cnt[n]]--;
        freq[++cnt[n]]++;
    }

    void deleteOne(int n)
    {
        if (cnt[n]) {
            freq[cnt[n]]--;
            freq[--cnt[n]]++;
        }
    }

    bool hasFrequency(int f)
    {
        return freq[f];
    }
};


class FrequencyTracker
{
    unordered_map<int, int> mp, fmap;
public:
    FrequencyTracker() {}

    void add(int n)
    {
        if (mp.count(n) && fmap.count(mp[n]))
            fmap[mp[n]]--;

        mp[n]++;
        fmap[mp[n]]++;
    }

    void deleteOne(int n)
    {
        if (mp.count(n) && fmap.count(mp[n]))
            fmap[mp[n]]--;
            
        if (mp.count(n))
        {
            mp[n]--;
            if (mp[n] == 0)
                mp.erase(n);
        }
        
        if (mp.count(n))
            fmap[mp[n]]++;
    }

    bool hasFrequency(int f)
    {
        if (!f)
            return 0;
        return fmap.count(f) && fmap[f];
    }
};
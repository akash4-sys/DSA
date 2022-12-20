#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTree
{
    vector<int> t;
    int n;
public:
    SegmentTree(int _n): n(_n), t(2 * _n, 0) {}

    void update(int pos, int val)
    {
        pos += n;
        t[pos] = val;
        while (pos > 1)
            pos >>= 1, t[pos] = max(t[2 * pos], t[2 * pos + 1]);
    }

    int query(int low, int high)
    {
        low += n, high += n;
        int ans = 0;
        while (low < high)
        {
            if (low & 1)
                ans = max(ans, t[low++]);
            if (high & 1)
                ans = max(ans, t[--high]);
            low >>= 1;
            high >>= 1;
        }
        return ans;
    }
};
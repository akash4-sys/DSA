#include "../../headers.h"

class SnapshotArray
{
    int snapId = 0;
    vector<vector<pair<int, int>>> snaps;

public:
    SnapshotArray(int len)
    {
        snapId = 0;
        snaps.resize(len);
        for (int i = 0; i < len; i++)
            snaps[i].push_back({0, 0});
    }

    void set(int i, int val)
    {
        snaps[i].push_back({snapId, val});
    }

    int snap()
    {
        return snapId++;
    }

    int get(int i, int snap_id)
    {
        pair<int, int> p = {snap_id, INT_MAX};
        return prev(upper_bound(snaps[i].begin(), snaps[i].end(), p))->second;
    }
};



// Time Complexity - O(N)
// Space Complexity - O(N^2)

class SnapshotArray
{
    vector<vector<int>> snaps;
    vector<int> v;
    int snapId = 0;

public:
    SnapshotArray(int len)
    {
        v = vector<int>(len);
    }

    void set(int i, int val)
    {
        v[i] = val;
    }

    int snap()
    {
        snaps.push_back(v);
        return snapId++;
    }

    int get(int i, int snap_id)
    {
        return snaps[snap_id][i];
    }
};
#pragma once

#include <vector>
#include <string>

using namespace std;

// ! zArray[0] = 0, though it should be equal to s.size()

class zAlgorithm
{
    vector<int> zAlgo(string &s)
    {
        int n = s.size(), x = 0, y = 0;
        vector<int> zArray(n);
        for (int i = 1; i < n; i++)
        {
            zArray[i] = max(0, min(zArray[i - x], y - i + 1));
            while (i + zArray[i] < n && s[zArray[i]] == s[i + zArray[i]])
                x = i, y = i + zArray[i], zArray[i]++;
        }
        return zArray;
    }
};
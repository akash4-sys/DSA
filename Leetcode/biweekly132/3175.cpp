#include "../../headers.h"

class Solution {
public:
    int findWinningPlayer(vector<int> &v, int k)
    {
        int n = v.size(), x = *max_element(v.begin(), v.end());
        for (int i = 0, j = 1, c = 0; i < n; j++)
        {
            if (v[i] < v[j])
                i = j, c = 1;
            if (j - i + c >= k || v[i] == x)
                return i;
        }
        return -1;
    }
};
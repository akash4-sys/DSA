#include "../../headers.h"

class Solution {
public:
    int countCompleteDayPairs(vector<int>& v) {
        int n = v.size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((v[i] + v[j]) % 24 == 0)
                    ans++;
        return ans;
    }
};
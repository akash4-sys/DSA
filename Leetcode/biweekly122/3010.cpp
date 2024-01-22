#include "../../headers.h"

class Solution {
public:
    int minimumCost(vector<int> &v) {
        sort(v.begin() + 1, v.end());
        return v[0] + v[1] + v[2];
    }
};
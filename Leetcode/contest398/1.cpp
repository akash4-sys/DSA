#include "../../headers.h"

class Solution {
public:
    bool isArraySpecial(vector<int>& v) {
        for (int i = 1; i < v.size(); i++)
            if (v[i] % 2 == v[i - 1] % 2)
                return 0;
        return 1;
    }
};
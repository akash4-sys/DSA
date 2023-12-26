#include "../../headers.h"

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& v) {
        int n = v.size(), j = n - 1;
        for (; j > 1 && v[j - 1] < v[j]; j--);

        if (!j)
            return n * (n + 1) / 2;

        long long ans = n - j + 1;
        for (int i = 1; i < n; i++) {
            for (j = max(i + 1, j); j < n && v[i - 1] >= v[j]; j++);
            ans += n - j + 1;
            if (v[i - 1] >= v[i])
                break;
        }
        return ans;
    }
};
#include "../../headers.h"

class Solution
{
public:
    int minSwapsCouples(vector<int> &v)
    {
        int ans = 0, n = v.size();
        vector<int> pos(n, 0);
        for (int i = 0; i < n; i++)
            pos[v[i]] = i;

        auto ptn = [](int n){
            return n & 1 ? n - 1 : n + 1;
        };
        
        for (int i = 0; i < n; i++)
            for (int j = ptn(pos[ptn(v[i])]); i != j; j = ptn(pos[ptn(v[i])]))
                swap(v[i], v[j]), swap(pos[v[i]], pos[v[j]]), ans++;
        return ans;
    }
};
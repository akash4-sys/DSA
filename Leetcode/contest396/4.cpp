#include "../../headers.h"

class Solution
{
public:
    int minCostToEqualizeArray(vector<int> &v, int k1, int k2)
    {
        long long mod = 1e9 + 7, n = v.size(), ans = 0, i = 0, j = n - 2;
        sort(v.begin(), v.end());
        
        if (k1 <= k2) {
            for (int &a : v)
                ans = (ans + ((1LL * (v.back() - a) * k1) % mod)) % mod;
            return ans;
        }

        while (i < j)
        {
            long long needed = v[j + 1] - v[j], cando = v.back() - v[i];
            if (needed < cando) {
                (ans += needed * k2) %= mod;
                v[j] = v[j + 1];
                v[i] += needed;
                j--;
            }
            else if (needed > cando) {
                (ans += cando * k2) %= mod;
                v[i] = v.back();
                v[j] += cando;
                i++;
            }
            else if (needed == cando) {
                (ans += cando * k2) %= mod;
                v[j] = v[i] = v.back();
                i++, j--;
            }
        }

        if (v[i] != v.back())
        {
            long long cost = INT_MAX, needed = v.back() - v[i];
            if (needed % (n - 1) == 0) {
                
            }
        }
        return ans;
    }
};
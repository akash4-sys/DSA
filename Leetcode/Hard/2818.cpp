#include "../../headers.h"

class Solution
{
    long long power(long long a, long long b, long long mod)
    {
        long long res = 1;
        for (a %= mod; b > 0; b >>= 1)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
        }
        return res;
    }

public:
    int maximumScore(vector<int> &a, int k)
    {
        long long ans = 1, mod = 1e9 + 7, n = a.size(), mx = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({a[i], i}), mx = max(mx, (long long)a[i]);

        sort(v.begin(), v.end(), greater<pair<int, int>>());
        vector<int> l(n, -1), r(n, n), st, prime(mx + 1, 1), pFactors(mx + 1, 0);

        for (int i = 2; i <= mx; i++)
            if (prime[i])
                for (int j = i; j <= mx; j += i)
                    pFactors[j]++, prime[j] = 0;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && pFactors[a[st.back()]] < pFactors[a[i]])
                st.pop_back();
            l[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        st.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && pFactors[a[st.back()]] <= pFactors[a[i]])
                st.pop_back();
            r[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        for (int i = 0; i < n && k; i++)
        {
            int num = v[i].first, it = v[i].second;
            int op = min((it - l[it]) * (r[it] - it), k);
            ans = (ans * power(num, op, mod)) % mod;
            k -= op;
        }
        return ans;
    }
};
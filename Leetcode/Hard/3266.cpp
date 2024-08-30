
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

    vector<int> create(vector<vector<long long>> &a) {
        vector<int> ans(a.size());
        for (int i = 0; i < a.size(); i++)
            ans[a[i][1]] = a[i][0];
        return ans;
    }

public:
    vector<int> getFinalState(vector<int> &v, int k, int m)
    {
        int n = v.size(), mod = 1e9 + 7;
        vector<vector<long long>> a;
        for (int i = 0; i < n; i++)
            a.push_back({v[i], i});
        
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            while (k && (a[i][0] * m) % mod <= a[i][1])
                (a[i][0] *= m) %= mod, k--;
        
        if (!k)
            return create(a);
        
        vector<int> extra(n, 0);
        for (int i = 0; i < n - 1; i++)
            if (k && a[i + 1][0] == (a[i][0] * m) % mod)
                extra[i]++, k--;
        
        for (int i = 0; i < n; i++) {
            int p = (k / n) + extra[i];
            (a[i][0] *= power(m, p, mod)) %= mod;
        }

        if (k % n == 0)
            return create(a);

        for (int i = 0; i < n && k; i++)
            (a[i][0] *= m) %= mod, k--;
        return create(a);
    }
};
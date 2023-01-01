#include "headers.h"

#define vv vector<vector<int>>
#define vec vector<int>
#define vvv vector<vector<vector<int>>>
#define pb push_back
#define p pair<int, int>
#define ll long long
#define vp vector<p>
#define pp pop_back
#define t tuple<int, int, int>
#define loop(i, n) for (int i = 0; i < n; i++)
#define eloop(i, n) for (int i = 0; i <= n; i++)
#define rloop(i, n) for (int i = n; i >= 0; i--)
#define gloop(i, n) for (int i = n; i > 0; i--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define fs first
#define sc second
#define all(v) v.begin(), v.end()
#define rall(v) v.begin(), v.end()

class Solution
{
    unordered_map<int, int> c;
    void fun(int n)
    {
        while (n % 2 == 0)
            c[2] = 1, n = n / 2;

        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                c[i] = 1;
                n = n / i;
            }
        }
        if (n > 2)
            c[n] = 1;
    }

public:
    int distinctPrimeFactors(vector<int> &v)
    {
        for (int n: v)
            fun(n);
        
        int ans = 0;
        // for (auto [n, x]: c)
            // if ()
        return c.size();
    }
};
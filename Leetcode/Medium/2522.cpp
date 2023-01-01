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
#define fs first
#define sc second
#define all(v) v.begin(), v.end()
#define rall(v) v.begin(), v.end()


class Solution
{
public:
    int minimumPartition(string s, int k)
    {
        int res = 0; 
        long long n = 0;
        for (int i = 0; i < s.size(); i++)
        {
            n = (n * 10) + (s[i] - '0');
            if (s[i] - '0' > k) return -1;
            if (n > k) res++, n = n % 10;
        }
        res += (n <= k);
        return res;
    }
};
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
public:
    int countDigits(int n)
    {
        int c[10] = {0}, num = n;
        while (n > 0)
        {
            int x = n % 10;
            c[x] += (num % x == 0);
            n /= 10;
        }

        int ans = 0;
        for (int i = 0; i < 10; i++)
            ans += c[i];
        return ans;
    }
};
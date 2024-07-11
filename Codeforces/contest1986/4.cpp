#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << endl

int solve()
{
    int n = II, ans = INT_MAX;
    string s = SS;
    for (int i = 0; i < n - 1; i++)
    {
        int val = 0, a[21] = {0};
        for (int j = 0, k = 0; j < n; j++, k++)
            if (j == i)
                a[k] = (s[i] - '0') * 10 + (s[i + 1] - '0'), j++;
            else
                a[k] = s[j] - '0';
        
        if (*min_element(a, a + n - 1) == 0)
            return 0;
        
        for (auto x : a)
            if (x != 1)
                val += x;
        
        if (!val)
            val = 1;
        ans = min(ans, val);
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}
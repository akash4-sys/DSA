#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int n = II, time = II, ans = 0;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {II, II}, swap(v[i][0], v[i][1]);
    
    sort(v.begin(), v.end());
    for (int l = 0; l < n; l++)
    {
        multiset<int> st;
        for (int r = l, sum = 0; r < n; r++)
        {
            st.insert(v[r][1]);
            sum += v[r][1];
            while (!st.empty() && v[r][0] - v[l][0] + sum > time)
                sum -= *st.rbegin(), st.extract(*st.rbegin());
            ans = max(ans, (int)st.size());
        }
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}
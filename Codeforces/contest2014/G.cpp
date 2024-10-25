#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

ll solve()
{
    ll n = II, m = II, k = II;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        int a = II, b = II;
        mp[a] += b;
    }
    mp[1e18] = 0;

    ll currD = 1, sum = 0, res = 0;
    stack<pair<ll, ll>> st;
    for (auto &cur : mp)
    {
        while (st.size() && currD < cur.first)
        {
            auto [d, a] = st.top();
            st.pop();

            if (d + k - 1 < currD)
                continue;
            if (d > currD)
                currD = d, sum = 0;
            
            sum += a;
            if (m <= sum) {
                ll last_day = min({currD + (a + sum - m) / m + 1, d + k, cur.first});
                ll rem = a + sum - (last_day - currD) * m;
                res += last_day - currD;
                sum = 0;
                currD = last_day;
                if (rem)
                    st.push({d, rem});
            }
        }
        st.push(cur);
    }
    return res;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}
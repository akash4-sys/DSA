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
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}

void generateLenOfSubseq(vec &lengths, ll x)
{
    while (__builtin_popcount(x) != 1)
    {
        ll cnt = __builtin_popcount(x);
        for (ll i = 1; i < 64; i++)
            if (x & (1LL << i))
                lengths.push_back(i);
        x = cnt;
    }
    lengths.push_back(log2(x));
}

vec compressLength(vec &lengths)
{
    map<int, int> mp;
    for (ll len : lengths)
        mp[len]++;
    
    for (auto &[len, f] : mp)
        if (f > 1)
        {
            for (ll i = 0; i < 64; i++)
                if (f & (1LL << i))
                    mp[len + i]++;
            f = 0;
        }

    vec res;
    for (auto &[len, f] : mp)
        if (f > 0)
            res.push_back(len);
    return res;
}

vec solve()
{
    ll x = LL;
    vec lengths, ans;
    generateLenOfSubseq(lengths, x);
    lengths = compressLength(lengths);

    // For each length create a array
    ll start = 1000;
    for (ll len : lengths) {
        start -= len + 1;
        for (ll i = start; len--; i++)
            ans.push_back(i);
    }
    pl(ans.size());
    return ans;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pv(solve());
    return 0;
}
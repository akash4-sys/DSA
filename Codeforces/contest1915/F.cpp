#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define p pair<ll, ll>
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void mergeCount(vector<p> &vidx, vector<p> &merged, vec &ans, int low, int high)
{
    if(low >= high)
        return;
    ll mid = low + ((high - low) / 2);
    mergeCount(vidx, merged, ans, low, mid);
    mergeCount(vidx, merged, ans, mid + 1, high);

    ll l = low,  r = mid + 1, inverse = 0, i = low;
    while(l <= mid && r <= high)
        if(vidx[r].first < vidx[l].first)
            ++inverse, merged[i++] = vidx[r++];
        else
            ans[vidx[l].second] += inverse, merged[i++] = vidx[l++];

    while(l <= mid)
        ans[vidx[l].second] += inverse, merged[i++] = vidx[l++];

    while(r <= high)
        merged[i++] = vidx[r++];

    for(ll i = low; i <= high; i++)
        vidx[i] = merged[i];
}

vec countSmaller(vec &v) 
{
    vec ans(v.size(), 0);
    vector<p> vidx, merged;

    for(ll i = 0; i < v.size(); i++)
        vidx.push_back({v[i], i}), merged.push_back({v[i], i});

    mergeCount(vidx, merged, ans, 0, v.size() - 1);
    reverse(all(ans));
    return ans;
}

ll solve()
{
    ll n = LL, ans = 0;
    vv v(n);
    for (auto &r : v) {
        ll st = LL, en = LL;
        r = {en, st};
    }

    sort(all(v));
    vec ends;
    for (int i = n - 1; i >= 0; i--)
        ends.push_back(v[i][1]);
    
    vec smaller = countSmaller(ends);
    for (int i = 0; i < n; i++)
        ans += i - smaller[i];
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
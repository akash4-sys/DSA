#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec suffix1(vec &a, vec &b, vec &wt, int len)
{
    vec wtsf;
    for (ll i = len - 1, cnt = 0, sum = 0; i >= 0; i--)
    {
        cnt += a[i] > b[i];
        wt[i] = cnt;
        if (a[i] > b[i]) {
            sum += b[i];
            wtsf.push_back(sum);
        }
    }
    return wtsf;
}

vec suffix(vec &a, vec &b, vec &wp, int len)
{
    vec wpsf;
    for (ll i = len - 1, cnt = 0, sum = 0; i >= 0; i--)
    {
        cnt += a[i] < b[i];
        wp[i] = cnt;
        if (a[i] < b[i]) {
            sum += a[i];
            wpsf.push_back(sum);
        }
    }
    return wpsf;
}

vec prefix1(vec &a, vec &b, vec &st, int len)
{
    vec tpf;
    for (ll i = 0, cnt = 0, sum = 0; i < len; i++)
    {
        cnt += (a[i] < b[i]);
        st[i] = cnt;
        if (a[i] < b[i]) {
            sum += b[i];
            tpf.push_back(sum);
        }
    }
    return tpf;
}

vec prefix(vec &a, vec &b, vec &sp, int len)
{
    vec ppf;
    for (ll i = 0, cnt = 0, sum = 0; i < len; i++)
    {
        cnt += (a[i] > b[i]);
        sp[i] = cnt;
        if (a[i] > b[i]) {
            sum += a[i];
            ppf.push_back(sum);
        }
    }
    return ppf;
}

ll calc(int len, int n, int m, vec &sp, vec &wp, int a, int b, int i, vec &ppf, vec &wpsf)
{
    ll sum = 0;
    if (a > b)
    {
        if (n < sp[i])
            sum += ppf[n - 1];
        else
        {
            if (n < sp[len - 1] - 1) {
                sum += ppf[n];
                sum -= a;
            }
            else {
                sum += ppf.back();
                int r = n - ppf.size() - 1;
                sum += wpsf[wpsf.size() - r + 1];
           }
        }
    }
    else
    {
        if (n < sp[i])
            sum += ppf[n - 1];
        else
        {
            if (n < ppf.size())
                sum += ppf[n - 1];
            else
            {
                sum += ppf.back();
                int r = n - ppf.size();
                int j = wpsf.size() - r + 1;
                if (wp[i] > r)
                    sum += wpsf[j];
                else {
                    sum += wpsf[j - 1];
                    sum -= a;
                }
            }
        }
    }
    return sum;
}

vec solve()
{
    ll n = LL, m = LL, len = n + m + 1;
    vec sp(len, 0), wp(len, 0), a(len), b(len), st(len, 0), wt(len, 0);
    iv(a);
    iv(b);
    vec ppf = prefix(a, b, sp, len);
    vec tpf = prefix1(a, b, st, len);
    vec wpsf = suffix(a, b, wp, len);
    vec wtsf = suffix1(a, b, wt, len);

    vec ans(len, 0);
    for (int i = 0; i < len; i++)
        ans[i] = calc(len, n, m, sp, wp, a[i], b[i], i, ppf, wpsf)
            + calc(len, n, m, st, wt, a[i], b[i], i, tpf, wtsf);
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}
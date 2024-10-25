#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    ll n = II;
    vector<ll> pos, neg;
    for (int i = 0; i < n; i++) {
        ll a = LL;
        if (a >= 0)
            pos.push_back(a);
        else
            neg.push_back(a);
    }

    if (n == 1 || neg.empty()) {
        pl("NO");
        return;
    }

    sort(all(pos));
    sort(all(neg));
    ll c = pos.back() - neg[0], sum = 0;

    cout << "Yes\n";
    while (pos.size() || neg.size())
    {
        if (pos.size()) {
            while (pos.size() && sum + pos.back() < c) {
                cout << pos.back() << " ";
                sum += pos.back();
                pos.pop_back();
            }
        }

        ll x = pos.size() ? pos.back() : c * 10;
        while (neg.size() && sum + x >= c) {
            cout << neg.back() << " ";
            sum += neg.back();
            neg.pop_back();
        }
    }
    cout << "\n";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}
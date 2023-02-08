#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(vv) { for(auto &v : vv) pv(v), br; }

int main()
{
    fast;
    int x1 = II, y1 = II, x2 = II, y2 = II, b = 0;
    if (abs(x1 + x2) % 2 == abs(y1 + y2) % 2)
        b = (abs(x1 - x2) == abs(y1 - y2)) ? 1 : 2;
    int r = (x1 - x2 && y1 - y2) ? 2 : 1;
    int k = max(abs(x1 - x2), abs(y1 - y2));
    cout<<r<<" "<<b<<" "<<k<<endl;
    return 0;
}
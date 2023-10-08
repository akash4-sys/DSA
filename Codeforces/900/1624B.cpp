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
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

string solve()
{
    int a = II, b = II, c = II;

    int new_a = b - (c - b);
    if(new_a >= a && new_a % a == 0 && new_a != 0)
        return "YES";

    int new_b = a + (c - a)/2;
    if(new_b >= b && (c-a)%2 == 0 && new_b % b == 0 && new_b != 0)
        return "YES";

    int new_c = a + 2*(b - a);
    if(new_c >= c && new_c % c == 0 && new_c != 0)
        return "YES";
    
    return "NO";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}
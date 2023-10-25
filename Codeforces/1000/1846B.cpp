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

bool won(vector<string> &v, char x)
{
    for (int i = 0; i < 3; i++)
    {
        int cnt = count(all(v[i]), x);
        if (cnt == 3)
            return 1;
    }

    for (int j = 0; j < 3; j++)
    {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            cnt += v[i][j] == x;
        if (cnt == 3)
            return 1;
    }

    int cnt = 0;
    for (int i = 0; i < 3; i++)
        cnt += v[i][i] == x;
    
    if (cnt == 3)
        return 1;

    cnt = 0;
    for (int i = 0, j = 2; i < 3; i++, j--)
        cnt += v[i][j] == x;
    return cnt == 3;
}

string solve()
{
    vector<string> v(3);
    iv(v);
    if (won(v, 'X'))
        return "X";
    if (won(v, 'O'))
        return "O";
    if (won(v, '+'))
        return "+";
    return "DRAW";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}
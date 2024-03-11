#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define vv vector<vec>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << endl

int dfs(vv &tree, string &s, int i)
{
    if (!i)
        return tree.size();
    if (!tree[i][0] && !tree[i][1])
        return 0;

    int res = dfs(tree, s, tree[i][0]) + (s[i - 1] != 'L');
    return res = min(res, dfs(tree, s, tree[i][1]) + (s[i - 1] != 'R'));
}

int solve()
{
    int n = II;
    string s = SS;
    vv tree(n + 1, vec(2, 0));
    for (int i = 1; i <= n; i++)
        tree[i] = {II, II};
    return dfs(tree, s, 1);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}
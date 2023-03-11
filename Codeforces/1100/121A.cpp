#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

typedef long long ll;
ll a[100000];
ll t = 0;
ll res;
void dfs(long long num, int l)
{
    a[t++] = num;
    if (l > 11)
    {
        return;
    }
    dfs(num * 10 + 4, l + 1);
    dfs(num * 10 + 7, l + 1);
}

ll sum(int x)
{
    ll t1 = 0;
    ll ans = 0;
    for (int i = 1; i <= x; i++)
    {
        while (a[t1] < i)
            t1++;
        ans += a[t1];
    }
    return ans;
}

int main()
{
    dfs(0, 0);
    sort(a, a + t);
    int l, r;
    cin >> l >> r;
    cout << sum(r) - sum(l - 1);
}
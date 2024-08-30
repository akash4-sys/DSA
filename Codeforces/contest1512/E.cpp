#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void solve()
{
    int n = II, l = II, r = II, t = II;
    int cnt = r - l + 1, sum = cnt * (cnt + 1) / 2;
    vector<int> vis(n + 1, 0), taken, not_taken;
    for (int i = 1; i <= cnt; i++)
        vis[i] = 1;
    
    for (int i = cnt; i > 0 && sum != t; i--)
    {
        int best_fit = 0;
        sum -= i;
        for (int a = i; a <= n; a++)
            if (!vis[a] && sum + a <= t)
                best_fit = a;
        if (best_fit)
            sum += best_fit, vis[best_fit] = 1, vis[i] = 0;
        else
            sum += i;
    }

    if (sum != t) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; i++)
        if (vis[i])
            taken.push_back(i);
        else
            not_taken.push_back(i);
    
    for (int i = 1; i <= n; i++)
        if (l <= i && i <= r) {
            cout << taken.back() << " ";
            taken.pop_back();
        }
        else {
            cout << not_taken.back() << " ";
            not_taken.pop_back();
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
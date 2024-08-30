#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"

void solve()
{
    int n = II;
    vector<int> vis(n + 1, 0);
    if (n < 4) {
        pl(-1);
        return;
    }

    if (n == 4) {
        pl("3 1 4 2");
        return;
    }

    int i = 1;
    for (; i <= n; i += 2)
        vis[i] = 1, cout << i << " ";
    
    auto fill = [&](int st, vector<int> arr) {
        for (int a : arr)
            if (i + a > 0 && i + a <= n && !vis[i + a])
                i += a, vis[i] = 1, pf(i);
            else
                break;
    };
    
    if (n % 2 == 0)
        fill(i, {-5, 4, -2, -4});
    else
        fill(i, {-5, 2, -4});
    
    while (i - 2 > 0 && !vis[i - 2])
        i -= 2, vis[i] = 1, pf(i);
    cout << "\n";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}
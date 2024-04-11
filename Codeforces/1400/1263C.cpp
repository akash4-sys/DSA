#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

// Try to understand it's solutions they are preety good
// ! This is just a brute force approach

map<int, int> solve()
{
    int n = II;
    queue<int> q;
    for (int i = 1, sq = sqrt(n); i <= sq; i++)
        if (n % i == 0)
        {
            if (n / i != i)
                q.push(n / i);
            q.push(i);
        }
    
    map<int, int> mp;
    while (!q.empty())
        for (int m = q.size(); m > 0; m--)
        {
            int r = q.front();
            q.pop();
            if (r && !mp.count(n / r))
                mp[n / r] = 1, q.push(n / r);
            if (!mp.count(n / (r + 1)))
                mp[n / (r + 1)] = 1, q.push(n / (r + 1));
            if (r > 1 && !mp.count(n / (r - 1)))
                mp[n / (r - 1)] = 1, q.push(n / (r - 1));
        }
    return mp;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        auto st = solve();
        cout << st.size() << "\n";
        for (auto &it : st)
            cout << it.first << " ";
        cout << "\n";
    }
    return 0;
}
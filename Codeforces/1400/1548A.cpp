#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, m = II, alive = n;
    vector<int> to_kill(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u = II - 1, v = II - 1;
        if (u > v)
            swap(u, v);
        alive -= to_kill[u] == 0;
        to_kill[u]++;
    }

    for (int q = II; q--; )
    {
        int type = II;
        if (type < 3)
        {
            int u = II - 1, v = II - 1;
            if (u > v)
                swap(u, v);
            
            if (type == 1)
                alive -= ++to_kill[u] == 1;
            else
                alive += --to_kill[u] == 0;
        }
        else
            cout << alive << "\n";
    }
    return 0;
}
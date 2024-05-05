#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

// Correct solution
// ecernawala's solution
// haven't able to understand completely yet

int solve()
{
    int n = II, x = II, y = II, vertices = x;
    vector<int> a(x), gaps;
    for (int &p : a)
        p = II - 1;
    sort(all(a));

    for (int i = 0; i < x; i++) {
        int gap = (i + 1 == x ? a[0] + n : a[i + 1]) - a[i] - 1;
        if (gap % 2)
            gaps.push_back(gap);
    }

    sort(all(gaps));
    for (int g : gaps) {
        if (y < g / 2)
            break;
        y -= g / 2, vertices += g;
    }
    
    vertices += y * 2;
    return min(vertices, n) - 2;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}
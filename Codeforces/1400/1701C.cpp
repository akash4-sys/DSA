#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int n = II, m = II, l = 1, r = m * 2;
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++)
        cnt[II - 1]++;
    
    auto check = [&](int k) {
        long long free_slots = 0;
        for (int &a : cnt)
            free_slots += a <= k ? (k - a) / 2 : k - a;
        return free_slots >= 0;
    };
    
    while (l <= r) {
        int mid = (l + r) / 2;
        check(mid) ? r = mid - 1 : l = mid + 1;
    }
    return l;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}
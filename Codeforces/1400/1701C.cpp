#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

bool check(vector<int> &cnt, int t)
{
    long long tasks_slots_rem = 0, undone_tasks = 0;
    for (int c : cnt)
        if (t >= c)
            tasks_slots_rem += (t - c) / 2;
        else
            undone_tasks += (c - t);
    return undone_tasks <= tasks_slots_rem;
}

int solve()
{
    int n = II, m = II, k = 0, l = 1, r = m * 2;
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++)
        k += (++cnt[II - 1] == 1);
    
    if (n >= m)
        return k == m ? 1 : 2;
    if (n < m && k == m)
        return ceil(m / n * 1.0);
    
    while (l <= r) {
        int mid = (l + r) / 2;
        check(cnt, mid) ? r = mid - 1 : l = mid + 1;
    }
    return r + 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}
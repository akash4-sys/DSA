#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl
#define iv(v) { for(auto &x : v) cin >> x; }

bool notConsecutive(auto begin, auto end)
{
    set<int> st;
    for (auto it = begin; it != end; ++it)
        st.insert(*it);
    
    for (auto it = next(st.begin()); it != st.end(); it++)
        if (*it != *prev(it) + 1)
            return 1;
    return 0;
}

int mergeSort(auto begin, auto end)
{
    if (end - begin <= 1)
        return 0;
    if (notConsecutive(begin, end))
        return -1;

    auto mid = begin + (end - begin) / 2;
    int a = mergeSort(begin, mid), b = mergeSort(mid, end);

    if (a == -1 || b == -1)
        return -1;
    if (is_sorted(begin, end))
        return a + b;

    inplace_merge(begin, mid, end);
    return a + b + 1;
}

int solve()
{
    int n = II;
    vec v(n);
    iv(v);
    return mergeSort(v.begin(), v.end());
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}
#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

void primeFactors(int n, map<int, int> &cnt)
{
    if (n == 2)
        cnt[n]++;
    for (int i = 2, sq = sqrt(n); i <= sq; i++)
        for (; !(n % i); n /= i)
            cnt[i]++;
    if (n > 2)
        cnt[n]++;
}

string solve()
{
    int n = II;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
        primeFactors(II, cnt);
    
    for (auto it : cnt)
        if (it.second % n != 0)
            return "NO";
    return "YES";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}
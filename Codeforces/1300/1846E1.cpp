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
    int N = 1e6 + 1;
    vector<int> v(N, 0);
    for (int k = 2; k <= 1000; k++)
        for (int sum = 1 + k, leafs = k * k; sum + leafs < N; leafs *= k)
            v[sum += leafs] = 1;

    for (int t = II; t; t--)
        cout << (v[II] ? "YES" : "NO") << endl;
    return 0;
}
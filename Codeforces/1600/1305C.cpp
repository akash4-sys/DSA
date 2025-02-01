#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, m = II;
    vector<int> v(n);
    for (int &a : v)
        a = II;

    if (n > m) {
        cout << 0;   
        return 0;
    }

    long long ans = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            (ans *= abs(v[i] - v[j])) %= m;
    cout << ans;
    return 0;
}
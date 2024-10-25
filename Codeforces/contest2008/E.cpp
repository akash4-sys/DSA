#include <bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << "\n"

int solve()
{
    int n = II;
    string s = '#' + SS;
    if (n == 1)
        return 1;

    vv fq(2, vec(26, 0)), sf = fq;
    for (int i = n; i >= 1; i--)
        sf[i % 2][s[i] - 'a']++;

    if (n % 2 == 0)
        return n - *max_element(all(sf[0])) - *max_element(all(sf[1]));

    int ans = n + 1;
    for (int i = 1; i <= n; i++)
    {
        sf[i % 2][s[i] - 'a']--;
        int x = 0, y = 0;
        for (int j = 0; j < 26; j++) {
            x = max(x, fq[0][j] + sf[1][j]);
            y = max(y, fq[1][j] + sf[0][j]);
        }
        ans = min(ans, n - (x + y));
        fq[i % 2][s[i] - 'a']++;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}
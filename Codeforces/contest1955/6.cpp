#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int fq[5] = {0}, ans = 0;
    for (int i = 1; i < 5; i++)
        fq[i] = II, ans += (fq[i] / 2);
    return (fq[1] * fq[2] * fq[3]) % 2 + ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}
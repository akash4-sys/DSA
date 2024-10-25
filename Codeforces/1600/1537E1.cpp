#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    int n, k;
    string s, r = "";
    cin >> n >> k >> s;
    string ans(k, 'z');
    for (char &c : s)
    {
        r += c;
        n = r.size();
        string res = "";
        for (int m = k / n; m > 0; m--)
            res += r;
        if (k > res.size())
            res += r.substr(0, k - res.size());
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}
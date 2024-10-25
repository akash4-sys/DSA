#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    for (int tc = II; tc; tc--)
    {
        int l = II, r = II, c = 0;
        l += (l % 2 == 0);
        for (int i = l; i < r - 1; i++)
            if (__gcd(i, i + 1) == 1 && __gcd(i + 1, i + 2) == 1 && __gcd(i, i + 2) == 1) {
                c++;
                i += 2;
            }
        cout << c << endl;
    }
    return 0;
}
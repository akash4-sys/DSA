#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    string s;
    cin >> s;

    int v[6], ans = 3;
    for (int i = 0; i < 6; i++)
        v[i] = s[i] - '0';
    
    for (int a = 0; a <= 9; a++)
    for (int b = 0; b <= 9; b++)
    for (int c = 0; c <= 9; c++)
    for (int d = 0; d <= 9; d++)
    for (int e = 0; e <= 9; e++)
    for (int f = 0; f <= 9; f++)
        if ((a + b + c) == (d + e + f)) {
            int diff = v[0] != a;
            diff += v[1] != b;
            diff += v[2] != c;
            diff += v[3] != d;
            diff += v[4] != e;
            diff += v[5] != f;
            ans = min(ans, diff);
        }
    
    cout << ans;
    return 0;
}
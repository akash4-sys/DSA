#include <iostream>
#include <algorithm>
using namespace std;

int n, w, a;
long long s, mx, mn;
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        s += a;
        mx = max(mx, s);
        mn = min(mn, s);
    }
    cout << max(0LL, w - mx + mn + 1);
}
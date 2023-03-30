#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define II ({ int a; cin>>a; a; })
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define pi 3.14159265358979323846

int main()
{
    fast;
    double d = II, h = II, v = II, e = II;
    double area = (pi * d * d) / 4.0;
    double drinkSpeed = v / area;
    if (drinkSpeed <= e)
    {
        pl("NO");
        return 0;
    }

    double time = h / (drinkSpeed - e);
    pf("YES") << "\n" << setprecision(17) << time;
    return 0;
}
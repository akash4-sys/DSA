#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    long long ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ax -= bx, bx -= cx;
    ay -= by, by -= cy;
    int res = (ax * ax + ay * ay) == (bx * bx + by * by) && (ay != by || ax != bx);
    cout << (res ? "Yes" : "No");
    return 0;
}
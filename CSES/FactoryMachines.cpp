#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, total;
    cin >> n >> total;
    vector<int> v(n);
    for (int &a : v)
        cin >> a;
    
    long long l = 0, r = 1e18;
    while (l <= r)
    {
        long long time = l + ((r - l) / 2), tasks = 0;
        for (int &a : v)
            if ((tasks += time / a) >= total)
                break;
        if (total <= tasks)
            r = time - 1;
        else
            l = time + 1;
    }
    cout << r + 1;
    return 0;
}
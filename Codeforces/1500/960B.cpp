#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, k1 = II, k2 = II, k = k1 + k2;
    vector<int> a(n);
    for (int &x : a)
        x = II;
    
    priority_queue<long long> pq;
    for (int &x : a) {
        int m = abs(x - II);
        if (m)
            pq.push(m);
    }
    
    while (k && pq.size())
    {
        long long d = pq.top();
        pq.pop();
        d--, k--;
        if (d)
            pq.push(d);
    }

    if (k % 2) {
        cout << 1;
        return 0;
    }

    long long error = 0;
    while (!pq.empty())
        error += pq.top() * pq.top(), pq.pop();
    cout << error;
    return 0;
}
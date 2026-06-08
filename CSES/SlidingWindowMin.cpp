#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x,  A, B, C, res = 0;
    cin >> n >> k >> x >> A >> B >> C;
    vector<int> a;
    deque<int> dq;
    for (int i = 0; i < n; i++) {    
        a.push_back(x);
        while (dq.size() && a[dq.back()] > a[i]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front();
        if (i >= k - 1) res ^= a[dq.front()];
        x = ((1LL * A * x) % C + B) % C;
    }
    cout << res;
    return 0;
}
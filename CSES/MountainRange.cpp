#include <bits/stdc++.h>
using namespace std;
#define p pair<int, int>

int main()
{
    int n, ans = 0;
    cin >> n;
    priority_queue<p, vector<p>, greater<p>> pq;
    for (int i = 0; i < n; i++) {
        int a, cnt = 1;
        cin >> a;
        while (pq.size() && pq.top().first < a) {
            cnt = max(cnt, pq.top().second) + 1;
            pq.pop();
        }

        if (pq.size() && pq.top().first == a)
            cnt = max(cnt, pq.top().second), pq.pop();
        ans = max(ans, cnt);
        pq.push({a, cnt});
    }

    int cnt = 0;
    while (!pq.empty()) {
        cnt = max(cnt, pq.top().second) + 1;
        pq.pop();
    }
    cout << max(ans, cnt - 1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

struct Node { ll v, bus, walk; };

ll solve()
{
    ll n = II, m = II, eventStart = II, callStart = II, callEnd = II;
    vector<vector<Node>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u = II, v = II, bus = II, walk = II;
        Node node(v, bus, walk);
        g[u].push_back(node);
        node.v = u;
        g[v].push_back(node);
    }
    
    priority_queue<pair<ll, ll>> pq;
    vector<ll> vis(n + 1, 0), time(n + 1, INT_MIN);
    pq.push({eventStart, n});
    time[n] = eventStart;
    vis[0] = INT_MAX, time[0] = INT_MAX;

    while (!pq.empty())
    {
        auto [t, u] = pq.top();
        pq.pop();
        vis[u] = 1;

        if (t >= time[u]) {
            for (auto [v, bus, walk] : g[u])
                if (!vis[v])
                {
                    ll onCall = t >= callStart && t <= callEnd, timeTaken = INT_MIN;
                    if (t > callEnd && t - bus < callEnd)
                        onCall = 1;

                    if (onCall) {
                        timeTaken = t - walk;
                        if (callStart > t - walk)
                            timeTaken = max(callStart - bus, timeTaken);
                    }
                    else
                        timeTaken = t - bus;
                    if (timeTaken > time[v]) {
                        time[v] = timeTaken;
                        pq.push({timeTaken, v});
                    }
                }
        }
    }
    return max(time[1], -1LL);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}
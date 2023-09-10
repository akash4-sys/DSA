#include <iostream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <algorithm>
#include <set>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
int n;
bool vis[N];

void dfs(int u)
{
	vis[u] = true;
	for (auto v : adj[u])
		if (!vis[v])
			dfs(v);
	cout << u << ' ';
}

void solve()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		vis[i] = false;
		adj[i].clear();
	}
	vector<long long> a(n + 1), c(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		adj[a[i]].push_back(i);
	}

	vector<pair<long long, long long>> b;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		b.push_back(make_pair(c[i], i));
	}

	sort(b.begin(), b.end());
	for (auto [num, i] : b)
		if (!vis[i])
			dfs(i);

	cout << '\n';
	return;
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt = 1;
	cin >> tt;

	while (tt--)
		solve();
	return 0;
}

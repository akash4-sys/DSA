#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int sum[N + 100], ans[N + 100];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i)
            sum[j] += i;
    for (int i = 1; i <= N; i++)
        if (sum[i] <= N && !ans[sum[i]])
            ans[sum[i]] = i;

    int t, c;
    cin >> t;
    while (t--) {
        cin >> c;
        cout << (ans[c] ? ans[c] : -1) << "\n";
    }
    return 0;
}
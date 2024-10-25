#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

struct LazySum
{
    vector<int> pf;
    LazySum(int m) : pf(m, 0) {}
    void add(int l, int r) {
        if (l > r)
            return;
        pf[l]++;
        pf[r + 1]--;
    }

    void updateAndClear(vector<int> &dp) {
        int sum = 0;
        for (int i = 0; i < pf.size(); i++) {
            sum += pf[i];
            pf[i] = 0;
            if (i < dp.size())
                dp[i] += sum;
        }
    }
};

int main()
{
    fast;
    int n = II, m = II, pts = 0;
    vector<int> records(n), dp(m + 1, INT_MIN);
    for (int &r : records)
        r = II;
    
    dp[0] = 0;
    LazySum ls(m + 2);
    for (int &r : records)
        if (!r) {
            ls.updateAndClear(dp);
            for (int i = m; i > 0; i--)
                dp[i] = max(dp[i - 1], dp[i]);
            pts++;
        }
        else if (r > 0)
            ls.add(r, m);
        else
            ls.add(0, r + pts);

    ls.updateAndClear(dp);
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

// @ Classic Meet in Middle implementation from USACO for 1249C2

vector<ll> v;

vector<ll> subsetSum(int l, int r)
{
    vector<ll> res;
    for (int i = 0, len = r - l; i < (1 << len); i++) {
        ll sum = 0;
        for (int j = 0; j < len; j++)
            if (i & (1 << j))
                sum += v[l + j];
        res.push_back(sum);
    }
    return res;
}

ll solve(vector<ll> &left, vector<ll> &right)
{
    ll n = LL, ans = LLONG_MAX;
    for (ll a : left) {
        int i = lower_bound(right.begin(), right.end(), n - a) - right.begin();
        ans = min(ans, a + right[i]);
    }
    return ans;
}

int main()
{
    fast;
    for (ll x = 1; x <= 2e4; x *= 3LL)
        v.push_back(x);
    
    int n = v.size();
    auto left = subsetSum(0, n / 2 - 1);
    auto right = subsetSum(n / 2, n);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    cout << solve(left, right) << "\n";
    return 0;
}
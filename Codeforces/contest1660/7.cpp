#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })
#define SS ({ string s; cin >> s; s; })
#define pl(x) cout << x << "\n"

class BIT
{
    int n;
    vector<int> bit;
public:
    BIT(int _n): n(_n + 1), bit(_n + 1, 0) {}

    int getSum(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void add(int i) {
        for (++i; i < n; i += i & (-i))
            bit[i]++;
    }
};

ll solve()
{
    ll n = II, ans = 0;
    string s = SS;
    for (int x = 0; x < 3; x++)
    {
        BIT bit(n * 2 + 2);
        int bal = n, b = 0;
        if (x == 0)
            bit.add(n);

        for (char &c : s) {
            if (c == '-')
                b++, bal++;
            else
                b += 2, bal--;
            if (b % 3 == x)
                ans += bit.getSum(bal + 1), bit.add(bal);
        }
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}
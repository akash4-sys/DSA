#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

set<int> primeFactors(int n)
{
    set<int> s;
    if (n == 2)
        s.insert(n);
    for (int i = 2, sq = sqrt(n); i <= sq; i++)
        for (; !(n % i); n /= i)
            s.insert(i);
    if (n > 2)
        s.insert(n);
    return s;
}

int solve()
{
    int n = II, ans = 0, g = 0;
    vector<int> v(n);
    for (int &a : v)
        a = II, g = __gcd(g, a);
    
    vector<set<int>> factors(n);
    for (int i = 0; i < n; i++)
        v[i] /= g, factors[i] = primeFactors(v[i]);
    
    for (int i = 0; i < n; i++)
        for (int p: factors[i])
        {
            int l = (i + n - 1) % n, r = i, cnt = 0;
            while (factors[l].count(p)) {
                factors[l].erase(p);
                cnt++;
                if (--l < 0)
                    l = n - 1;
            }

            while (factors[r].count(p)) {
                if (r != i)
                    factors[r].erase(p);
                cnt++;
                r = (r + 1) % n;
            }
            ans = max(ans, cnt);
        }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}
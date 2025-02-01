#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << "\n"
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << "\n";}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
    {
        int n = II, k = II, m = log2(k);
        vector<int> v = {k - (1 << m), k + 1, k + (1 << m) + 1};
        for (int i = 0; i <= 19; i++)
            if (m != i)
                v.push_back(1 << i);
        pl(v.size());
        pv(v);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })
#define CC ({ char s; cin>>s; s; })

class BIT
{
    vector<int> bit;
    int n;

public:
    BIT(int _n): n(_n + 1), bit(_n + 1, 0) {}

    int getSum(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void add(int i, int val = 1) {
        for (++i; i < n; i += i & (-i))
            bit[i] += val;
    }
};

int main()
{
    fast;
    int n = II, m = II, q = II, cnt = 0;
    BIT bit(n * m);
    vector<string> v(n, "");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v[i] += CC;
            if (v[i][j] == '*')
                bit.add(n * j + i), cnt++;
        }

    while (q--)
    {
        int x = II - 1, y = II - 1, i = n * y + x;
        if (v[x][y] == '*')
        	bit.add(i, -1), cnt--, v[x][y] = '.';
        else
        	bit.add(i), cnt++, v[x][y] = '*';
        cout << cnt - bit.getSum(cnt - 1) << "\n";
    }
    return 0;
}
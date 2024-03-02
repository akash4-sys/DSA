#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl

bool getSum(vector<int> bits, int n)
{
    for (int i = 0; i < 30; i++)
        if (n & (1 << i))
        {
            int fq = 1;
            for (int j = i; j >= 0 && fq; j--, fq *= 2)
                if (bits[j] >= fq)
                    bits[j] -= fq, fq = 0;
                else
                    fq -= bits[j], bits[j] = 0;
            if (fq)
                return 0;
        }
    return 1;
}

int main()
{
    fast;
    vector<int> bits(30, 0);
    for (int q = II; q; q--)
    {
        int t = II;
        if (t == 1)
            bits[II]++;
        else
            getSum(bits, II) ? pl("YES") : pl("NO");
    }
    return 0;
}
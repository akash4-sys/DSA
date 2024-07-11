#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

int main()
{
    int t = II;
    while (t--)
    {
        int n = II, i = 1, r = n;
        set<int> ratings = {0};
        while (i <= r) {
            if (!ratings.count(n / i))
                ratings.insert(i);
            ratings.insert(n / i);
            r = n / i;
            i++;
        }
        cout << ratings.size() << endl;
        pv(ratings);
    }
    return 0;
}


// gen
int main()
{
    set<int> st;
    double n = 5;
    for (double i = 1; i <= n + 1; i++)
        if (!st.count(n / i)) {
        cout << i << " " << (n / i) << endl;
            st.insert(n / i);
        }
    
    cout << st.size();
}
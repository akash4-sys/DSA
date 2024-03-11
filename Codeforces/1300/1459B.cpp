#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

set<int> st;

void rec(int n, int x, int y, char prev_dir)
{
    if (n == 0) {
        st.insert(x * 10000 + y);
        return;
    }

    if (prev_dir == 'V')
        rec(n - 1, x + 1, y, 'H'), rec(n - 1, x - 1, y, 'H');
    else if (prev_dir == 'H')
        rec(n - 1, x, y + 1, 'V'), rec(n - 1, x, y - 1, 'V');
}

int main()
{
    int n;
    cin >> n;
    rec(n - 1, 0, 1, 'V');
    rec(n - 1, 0, -1, 'V');
    rec(n - 1, 1, 0, 'H');
    rec(n - 1, -1, 0, 'H');
    cout << st.size();
}
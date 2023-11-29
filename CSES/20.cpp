#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int n, x;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        st.insert(x);
    }
    cout << st.size();
    return 0;
}
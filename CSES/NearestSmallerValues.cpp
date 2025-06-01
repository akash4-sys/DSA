#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<vector<int>> st;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        while (!st.empty() && st.top()[0] >= a)
            st.pop();
        cout << (st.size() ? st.top()[1] : 0) << " ";
        st.push({a, i + 1});
    }
    return 0;
}
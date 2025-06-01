#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long sum = 0, prev = 0, b = k / 2, a = k / 2 - (k % 2 == 0);
    multiset<int> st;
    vector<int> v(n);
    for (int &x : v) {
        cin >> x;
        if (st.size() < k)
            st.insert(x);
    }

    auto med = next(st.begin(), k % 2 == 0 ? (k / 2) - 1 : (k / 2));
    prev = *med;
    for (int x : st)
        sum += abs(x - prev);
    cout << sum << " ";
    
    for (int i = 1; i <= n - k; i++)
    {
        st.insert(v[i + k - 1]);
        if (v[i + k - 1] < *med)
            med--;
        if (v[i - 1] <= *med)
            med++;
        st.erase(st.lower_bound(v[i - 1]));
        sum += abs(v[i + k - 1] - prev) - abs(v[i - 1] - prev) + (*med - prev) * (a - b);
        if (*med < prev)
            sum += *med - prev;
        else
            sum += prev - *med;
        cout << sum << " ";
        prev = *med;
    }
    return 0;
}
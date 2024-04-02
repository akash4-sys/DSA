#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

// ! Editorial solution is better

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int query(int i, int j, int mul = 0)
{
    cout << "? " << i << " " << i + 1 << "\n";
    fflush(stdout);
    cin >> mul;
    return mul;
}

int main()
{
    set<int> st = {4, 8, 15, 16, 23, 42};
    vector<int> v;
    for (int i = 1; i <= 4; i += 2)
    {
        int mul = query(i, i + 1);
        // wrong query
        if (mul == 0)
            return 0;

        for (int x : st)
            if (mul % x == 0 && st.find(mul / x) != st.end())
            {
                v.push_back(x);
                v.push_back(mul / x);
                st.erase(x);
                st.erase(mul / x);
                break;
            }
    }

    for (int x : st)
        v.push_back(x);

    int mul = query(2, 3);
    if (mul != v[1] * v[2])
    {
        if (v[0] * v[2] == mul)
            swap(v[0], v[1]);
        else if (v[1] * v[3] == mul)
            swap(v[2], v[3]);
        else if (v[0] * v[3] == mul)
            swap(v[0], v[1]), swap(v[2], v[3]);
    }
    
    mul = query(4, 5);
    if (mul != v[3] * v[4])
    {
        if (v[2] * v[4] == mul)
            swap(v[2], v[3]);
        else if (v[3] * v[5] == mul)
            swap(v[4], v[5]);
        else if (v[2] * v[5] == mul)
            swap(v[2], v[3]), swap(v[4], v[5]);
    }

    // print output
    cout << "! ";
    for (int x : v)
        cout << x << " ";
    
    cout << "\n";
    fflush(stdout);
    return 0;
}
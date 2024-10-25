#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

string generate(int n, int num) {
    if (n)
        return string(n, char(num + '0'));
    return string(1, char(!num + '0'));
}

bool query(string &q)
{
    cout << "? " << q << endl;
    int res = II;
    if (res == -1)
        exit(0);
    return res;
}

int binary_search(int l, int r, int num, string s = "", int onleft = 0)
{
    int res = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        string q = onleft ? generate(mid, num) + s : s + generate(mid, num);
        if (query(q))
            l = mid + 1, res = max(res, mid);
        else
            r = mid - 1;
    }
    return res;
}

string solve()
{
    int n = II, left = 0;
    int max_zero = binary_search(0, n, 0);
    int max_one = binary_search(0, n, 1);
    if (!max_one)
        return string(n, '0');
    if (!max_zero)
        return string(n, '1');

    string mz = generate(max_zero, 0), mo = generate(max_one, 1), s = "";
    string x = mz + mo;
    if (query(x))
        s = x, left = 1;
    else
        s = mo + mz;
    
    while (s.size() < n)
    {
        int right = !left, a, b;
        if (!left)
            a = binary_search(0, max_zero, 0, s, 1);
        else
            a = binary_search(0, max_one, 1, s, 1);

        if (!right)
            b = binary_search(0, max_zero, 0, s, 0);
        else
            b = binary_search(0, max_one, 1, s, 0);
        
        if (a)
            s = string(a, char(left + '0')) + s;
        if (b)
            s += string(b, char(right + '0'));
        left ^= 1;
    }
    return s;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << "! " << solve() << endl;
    return 0;
}
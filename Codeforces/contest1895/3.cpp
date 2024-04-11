#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SS ({ string s; cin>>s; s; })

int strsum(string &s) {
    int sum = 0;
    for (char &c : s)
        sum += (c - '0');
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &s : v)
        s = SS;
    
    vector<vector<int>> len_sum(6, vector<int>(46, 0));
    for (auto &s : v)
        len_sum[s.size()][strsum(s)]++;

    long long ans = 0;
    for (auto &s : v)
        for (int sum = strsum(s), a = s.size(), b = a % 2; b <= a; b += 2)
        {
            int len = a + b, pf = 0, sf = 0;
            for (int i = 0; i < len / 2; i++)
                pf += (s[i] - '0');
            for (int i = a - 1, m = len / 2; i >= 0 && m; m--, i--)
                sf += (s[i] - '0');
            
            ans += len_sum[b][max(pf * 2 - sum, 0)];
            if (a != b)
                ans += len_sum[b][max(sf * 2 - sum, 0)];
        }
    
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SS ({ string s; cin >> s; s; })

int main()
{
    string s = SS, p = SS;
    int n = s.size(), m = p.size(), ans = 0;
    vector<int> lps(m, 0);
    for (int i = 1, j = 0; i < m;)
        if (p[i] == p[j]) lps[i++] = ++j;
        else if (j) j = lps[j - 1];
        else i++;
    
    for (int i = 0, j = 0; i < n;) {
        if (s[i] == p[j])
            i++, j++;
        if (j == m) {
            ans++;
            j = lps[j - 1];
        }
        else if (i < n && s[i] != p[j])
            j ? j = lps[j - 1] : i++;
    }
    cout << ans;
    return 0;
}
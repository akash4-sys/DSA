#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

string solve()
{
    string s = SS;
    int k = II;
    while (1)
    {
        set<char> st(s.begin(), s.end());
        if (st.size() <= k)
            return s;
        
        st.clear();
        for (int i = 0; ; i++)
        {
            st.insert(s[i]);
            if (st.size() > k)
            {
                while (s[i] == '9')
                    i--;

                s[i]++;
                for (int j = i + 1; j < s.size(); j++)
                    s[j] = '0';
                break;
            }
        }
    }
    return "-1";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}
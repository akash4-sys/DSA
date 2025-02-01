#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"

int solve()
{
    string s = SS;
    int sortedPrefix = 0, nSortedPrefix = 0, nums = 0;
    for (char &c : s)
    {
        if (c == '+')
            nums++;
        else if (c == '-') {
            nums--;
            sortedPrefix = min(sortedPrefix, nums);
            if (nums < nSortedPrefix)
                nSortedPrefix = 0;
        }
        else if (c == '1')
            sortedPrefix = max(sortedPrefix, nums);
        else {
            if (nums <= 1)
                return 0;
            if (nSortedPrefix == 0 || nSortedPrefix > nums)
                nSortedPrefix = nums;
        }
        if (nSortedPrefix <= sortedPrefix && nSortedPrefix)
            return 0;
    }
    return 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}
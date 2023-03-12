#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << "\n"

int main()
{
    fast;
    string n = SS;
    unordered_map<int, int> mp = {{0, 2},{1, 7},{2, 2},{3, 3},{4, 3},{5, 4},{6, 2},{7, 5},{8, 1},{9, 2}};
    pl(mp[n[0] - '0'] * mp[n[1] - '0']);
    return 0;
}
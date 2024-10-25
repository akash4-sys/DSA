#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int n = II, l = 0, r = n;
    vector<vector<int>> v(n);
    for (auto &row : v)
        row = {II, II};
    
    auto check = [&](int x){
        int cnt = 0;
        for (auto &row : v)
            if (cnt + row[0] + 1 >= x && cnt <= row[1])
                cnt++;
        return cnt >= x;
    };
    
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}
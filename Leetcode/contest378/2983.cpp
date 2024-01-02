#include "../../headers.h"

// @ Tough to implement problem

class Solution
{
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>> &qrs)
    {
        int n = s.size();
        vector<int> pfd(1);
        for (int i = 0, j = n - 1; i < j; i++, j--)
            pfd.push_back(pfd.back() + (s[i] != s[j]));
        
        valarray<int> cnt(26);
        vector<valarray<int>> pfc(1, cnt);
        for (char &c : s)
        {
            cnt[c - 'a']++;
            pfc.push_back(cnt);
        }

        vector<bool> ans;
        for (auto &q : qrs)
        {
            int a1 = q[0], b1 = q[1] + 1, a2 = n - q[0], b2 = n - q[1] - 1;
            int c1 = q[2], d1 = q[3] + 1, c2 = n - q[2], d2 = n - q[3] - 1;

            if (min(a1, d2) && pfd[min(a1, d2)]
                || n / 2 > max(b1, c2) && pfd[n / 2] - pfd[max(b1, c2)]
                || d2 > b1 && pfd[d2] - pfd[b1]
                || a1 > c2 && pfd[a1] - pfd[c2]) {
                    ans.push_back(0);
            } else
            {
                valarray<int> x = pfc[d1] - pfc[c1], y = pfc[b1] - pfc[a1];
                if (a1 > d2)
                    x -= pfc[min(a1, c2)] - pfc[d2];
                if (c2 > b1)
                    x -= pfc[c2] - pfc[max(b1, d2)];
                if (c1 > b2)
                    y -= pfc[min(c1, a2)] - pfc[b2];
                if (a2 > d1)
                    y -= pfc[a2] - pfc[max(d1, b2)];
                ans.push_back((x >= 0 && y >= 0 && x == y).min());
            }
        }
        return ans;
    }
};
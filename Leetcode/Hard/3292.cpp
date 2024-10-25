#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> generateLPS(const string &p)
    {
        vector<int> lps(p.size(), 0);
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else i++;
        return lps;
    }
    
public:
    int minValidStrings(vector<string>& words, string target)
    {
        int len = target.size(), ans = 0;
        vector<int> max_len(len + 1, 0);
        for (auto &w : words)
        {
            auto lps = generateLPS(w + "#" + target);
            for (int i = 1; i <= len; i++)
                max_len[i] = max(max_len[i], lps[w.size() + i]);
        }

        for (; len && max_len[len]; ans++)
            len -= max_len[len];
        return len == 0 ? ans : -1;
    }
};
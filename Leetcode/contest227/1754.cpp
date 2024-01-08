#include "../../headers.h"

class Solution
{
public:
    string largestMerge(string s, string r)
    {
        string ans = "";
        int i = 0, j = 0, n = s.size(), m = r.size();
        while (i < n && j < m)
            if (s.compare(i, n - i, r, j, m - j) > 0)
                ans += s[i++];
            else
                ans += r[j++];
        return ans + s.substr(i) + r.substr(j);
    }
};


class Solution
{
public:
    string largestMerge(string s, string r)
    {
        if (s.size() == 0 || r.size() == 0)
            return s + r;
        if (s > r)
            return s[0] + largestMerge(s.substr(1), r);
        return r[0] + largestMerge(s, r.substr(1));
    }
};
#include "../../headers.h"

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        for (int a = 1; a <= 3; a++)
            for (int b = 1; b <= 3; b++)
                for (int c = 1; c <= 3; c++)
                    for (int d = 1; d <= 3; d++)
                        if (a + b + c + d == s.size())
                        {
                            int x = stoi(s.substr(0, a));
                            int y = stoi(s.substr(a, b));
                            int z = stoi(s.substr(a + b, c));
                            int w = stoi(s.substr(a + b + c, d));
                            if (x <= 255 && y <= 255 && z <= 255 && w <= 255)
                            {
                                string r = to_string(x) + "." + to_string(y) + "." + to_string(z) + "." + to_string(w);
                                if (r.size() == s.size() + 3)
                                    ans.push_back(r);
                            }
                        }
        return ans;
    }
};


// Time Complexity - O(M^N)
// Space Complexity - O(M^N)

class Solution
{
    vector<string> ans;
    void dfs(string &s, string r, string n, int i, int d)
    {
        if (i == s.size())
        {
            if (n.size() && stoll(n) <= 255 && (n.size() == 1 || n[0] != '0') && !d)
                ans.push_back(r + "." + n);
            return;
        }

        n += s[i];
        if (n.size() && stoll(n) <= 255 && (n.size() == 1 || n[0] != '0') && d)
            dfs(s, r + (r.empty() ? n : "." + n), "", i + 1, d - 1);
        dfs(s, r, n, i + 1, d);
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        dfs(s, "", "", 0, 3);
        return ans;
    }
};
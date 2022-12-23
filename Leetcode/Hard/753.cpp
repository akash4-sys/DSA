#include "../../headers.h"

// @ De Brujin's Sequence
// Related to euclidean path and circuit

class Solution
{
public:
    string crackSafe(int n, int k)
    {
        string ans(n, '0');
        unordered_set<string> vis;
        vis.insert(ans);

        for (int i = 0; i < pow(k, n); i++)
        {
            string prev = ans.substr(ans.size() - n + 1, n - 1);
            for (int j = k - 1; j >= 0; j--)
            {
                string now = prev + to_string(j);
                if (!vis.count(now))
                {
                    vis.insert(now);
                    ans += to_string(j);
                    break;
                }
            }
        }

        return ans;
    }
};
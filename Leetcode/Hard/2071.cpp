#include "../../headers.h"

class Solution
{
public:
    int maxTaskAssign(vector<int> &t, vector<int> &w, int pills, int strength)
    {
        sort(t.begin(), t.end(), greater<int>());
        sort(w.begin(), w.end(), greater<int>());

        int ans = 0, i = 0;
        while(i < w.size() && i < t.size())
        {
            if (w[i] >= t[i])
                ans++;
            else if (pills > 0 && (w[i] + strength) >= t[i])
            {
                pills--;
                ans++;
            }
            i++;
        }
        return ans;
    }
};
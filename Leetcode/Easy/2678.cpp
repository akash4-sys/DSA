#include "headers.h"

class Solution
{
public:
    int countSeniors(vector<string> &v)
    {
        int ans = 0;
        for (string s : v)
        {
            string r = s.substr(11, 2);
            if (r.empty())
                continue;
            int x = stoi(r);
            ans += x > 60;
        }
        return ans;
    }
};
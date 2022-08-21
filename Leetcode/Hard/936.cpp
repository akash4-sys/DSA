#include "../../headers.h"

class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> ans;
        auto totalLen = 0, turn_stamp = -1;
        while (turn_stamp)
        {
            turn_stamp = 0;
            for (int sz = stamp.size(); sz > 0; --sz)
            {
                for (int i = 0; i <= stamp.size() - sz; i++)
                {
                    string regex = string(i, '*') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
                    auto pos = target.find(regex);
                    while(pos != string::npos)
                    {
                        ans.push_back(pos);
                        turn_stamp += sz;
                        fill(begin(target) + pos, begin(target) + pos + stamp.size(), '*');
                        pos = target.find(regex);
                    }
                }
            }
            totalLen += turn_stamp;
        }
        reverse(ans.begin(), ans.end());
        return totalLen == target.size() ? ans : vector<int>();
    }
};
#include "../../headers.h"

class Solution
{
public:
    int openLock(vector<string>& deadends, string target)
    {
        vector<int> vis(10000, 0);
        for (auto &s : deadends)
            vis[stoi(s)] = 1;
        
        if (vis[0])
            return -1;
        
        queue<string> q({"0000"});
        for (int lvl = 0; !q.empty(); lvl++)
            for (int k = q.size(); k; k--)
            {
                string s = q.front();
                q.pop();
                if (s == target)
                    return lvl;
                
                for (int i = 0; i < 4; i++) {
                    int d = s[i] - '0';
                    for (int j = -1; j <= 1; j += 2)
                    {
                        s[i] = (d + j + 10) % 10 + '0';
                        int x = stoi(s);
                        if (!vis[x])
                            vis[x] = 1, q.push(s);
                    }
                    s[i] = d + '0';
                }
            }
        return -1;
    }
};
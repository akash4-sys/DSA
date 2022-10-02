#include "headers.h"

class LUPrefix
{
    vector<int> vis;
    int st = 1;
public:
    LUPrefix(int n)
    {
        vis = vector<int>(n + 1);
    }

    void upload(int i)
    {
        vis[i] = 1;
    }

    int longest()
    {
        for(int i = st; i < vis.size(); i++)
            if(!vis[i])
            {
                st = i;
                return i - 1;
            }
        return vis.size() - 1;
    }
};
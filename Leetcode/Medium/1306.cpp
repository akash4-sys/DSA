#include "../../headers.h"

class Solution
{
public:
    bool flag = false;
    void dfs(vector<int> &v, int i)
    {
        if(i < 0 || i >= v.size() || v[i] == 999)
            return;
        if(!v[i])
        {
            flag = true;
            return;
        }
        int x = v[i];
        v[i] = 999;
        dfs(v, i + x);
        dfs(v, i - x);
        return;
    }

    bool canReach(vector<int> &v, int s)
    {
        dfs(v, s);
        return flag;
    }
};
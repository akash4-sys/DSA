#include "../../headers.h"

class Solution 
{
public:
    int maxLength(vector<string>& v) 
    {
        int n = v.size(), ans = 0, allMask = 1 << n;
        for(int mask = 0; mask < allMask; mask++)
        {
            int sz = 0, flag = 1, vis = 0;
            for(int i = 0; i < n; i++)
            {
                if(((mask >> i) & 1) == 0)
                    continue;
                for(char c: v[i])
                {
                    flag = ((vis >> (c - 'a')) & 1) == 0;
                    if((vis >> (c - 'a')) & 1)
                        break;
                    vis |= (1 << (c - 'a'));
                    sz++;
                }
                if(!flag)
                    break;
            }
            if(flag && sz > ans)
                ans = sz;
        }
        return ans;
    }
};



class Solution 
{
public:
    int maxLength(vector<string>& v) 
    {
        int n = v.size(), ans = 0, allMask = 1 << n;
        for(int mask = 0; mask < allMask; mask++)
        {
            int sz = 0, flag = 1, vis[26] = {0};
            for(int i = 0; i < n; i++)
            {
                if(((mask >> i) & 1) == 0)
                    continue;
                for(char c: v[i])
                {
                    flag = vis[c - 'a'] == 0;
                    if(vis[c - 'a'])
                        break;
                    vis[c - 'a'] = 1;
                    sz++;
                }
                if(!flag)
                    break;
            }
            if(flag && sz > ans)
                ans = sz;
        }
        return ans;
    }
};
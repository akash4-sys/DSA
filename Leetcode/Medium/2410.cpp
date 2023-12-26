#include "headers.h"

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &p, vector<int> &t)
    {
        sort(p.begin(), p.end());
        multiset<int> st;
        for (int &a : t)
            st.insert(a);
        
        int ans = 0;
        for (int &a : p)
            if (auto it = st.lower_bound(a); it != st.end())
                st.erase(it), ans++;
        return ans;
    }
};


class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &pla, vector<int> &t)
    {
        vector<int> vis(t.size(), 0);
        int ans = 0, rem = t.size();
        sort(pla.begin(), pla.end());
        sort(t.begin(), t.end());
        for(int p: pla)
        {
            if(rem == 0)
                return ans;
            for(int i = 0; i < t.size(); i++)
            {
                if(!vis[i] && p <= t[i])
                {
                    ans++; 
                    rem--; 
                    vis[i] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
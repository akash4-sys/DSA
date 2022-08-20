#include "../../headers.h"

// Time complexity - O(N^2)
// Space complexity - O(N)
class Solution
{
public:
    int minRefuelStops(int target, int stFuel, vector<vector<int>> &st)
    {
        long long fuel[501] = {stFuel};
        for (int i = 0; i < st.size(); i++)
            for (int j = i; j >= 0 && fuel[j] <= st[i][0]; j--)
                fuel[j + 1] = max(fuel[j + 1], st[i][1] + fuel[j]);
        
        for(int i = 0; i < st.size(); i++)
            if(fuel[i] >= target)
                return i;
        return -1;
    }
};



// Time complexity  O(NLogN)
// Space complexity - O(N)


class Solution
{
public:
    int minRefuelStops(int target, int stFuel, vector<vector<int>> &st)
    {
        priority_queue<int> pq;
        int i = 0, ans = 0;
        for(ans = 0; stFuel < target; ans++)
        {
            while(i < st.size() && stFuel >= st[i][0])
                pq.push(st[i++][1]);
            if(pq.empty())
                return -1;
            stFuel += pq.top();
            pq.pop();
        }
        return ans;
    }
};
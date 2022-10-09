#include "../../headers.h"

class Solution 
{
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int> ans(n, 0);
        for(auto b: bookings)
        {
            ans[b[0] - 1] += b[2];
            // @ the reason we are not subtracting - 1 here as well if you checkout it's diagram
            // we had subtract the value of ans with ans[i - 2] wherever possible it's just that considering the indexes
            if(b[1] < n)
                ans[b[1]] -= b[2];
        }
        for(int i = 1; i < n; i++)
            ans[i] += ans[i - 1];
        return ans;
    }
}; 
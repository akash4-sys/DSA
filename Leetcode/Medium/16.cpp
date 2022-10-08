#include "../../headers.h"

class Solution
{
public:
    int threeSumClosest(vector<int> &v, int target)
    {
        sort(v.begin(), v.end());
        int ans = v[0] + v[1] + v[2];
        for(int i = 0; i < v.size(); i++)
        {
            int l = i + 1, r = v.size() - 1, sum;
            while(l < r)
            {
                sum = v[l] + v[r] + v[i];
                if(sum == target)
                    return sum;
                (sum < target) ? l++ : r--;
            }
            ans = ans < target ? max(ans, sum) : min(sum, ans);
        }
        return ans;
    }
};
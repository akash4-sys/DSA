#include "../../headers.h"

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &v)
    {
        vector<int> ans, lis;
        for (int n : v)
            if (lis.empty() || n >= lis.back()) {
                lis.push_back(n);
                ans.push_back((int)lis.size());
            }
            else {
                int i = upper_bound(lis.begin(), lis.end(), n) - lis.begin();
                lis[i] = n;
                ans.push_back(i + 1);
            }
        return ans;
    }
};
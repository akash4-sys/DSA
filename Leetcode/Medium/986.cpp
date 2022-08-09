#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &list1, vector<vector<int>> &list2)
    {
        vector<vector<int>> ans;
        if (list1.empty() || list2.empty())
            return ans;

        int i = 0, j = 0;
        while (i < list1.size() && j < list2.size())
        {
            int x = max(list1[i][0], list2[j][0]);
            int y = min(list1[i][1], list2[j][1]);

            if(x <= y)
                ans.push_back({x, y});
            
            if(list1[i][1] < list2[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};
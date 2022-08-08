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
        while (i < list1.size())
        {
            int cx, cy;
            if (i != 0 && list2[i - 1][1] == list1[i][0])
                ans.push_back({list1[i][0], list1[i][0]});

            if (list1[i][0] <= list2[i][0] && list1[i][1] >= list2[i][0])
            {
                cx = list2[i][0];
                cy = list2[i][1];
                ans.push_back({cx, cy});
            }

            
            i++;
        }
        return ans;
    }
};
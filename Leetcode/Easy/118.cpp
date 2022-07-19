#include "../../headers.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++)
        {
            vector<int> temp(i, 1);
            for(int j = 1; j < temp.size()-1; j++)
            {
                temp[j] = ans[i-2][j] + ans[i-2][j-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
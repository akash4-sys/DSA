
#include "../../headers.h"

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.length();
        if(n == 1 || numRows == 1)
            return s;
        string ans = "";
        int col = n / numRows;
        vector<vector<string>> grid(numRows, vector<string>(col, "0"));
        int j = 0, l = 0;
        while (l < n)
        {
            int i = 0, k = numRows - 2;
            while(i < numRows && l < n)
            {
                grid[i][j] = s[l];
                l++;
            }
            while(k > 0 && l < n)
            {
                j++;
                grid[k][j] = s[l];
                l++;
            }
            j++;
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int k = 0; k < grid[0].size(); k++)
            {
                if(grid[i][k] == "0")
                {
                    continue;
                }
                ans += grid[i][k];
            }
        }
        return ans;
    }
};
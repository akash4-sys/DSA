#include "../../headers.h"

// Solution 1
// By creating a matrix for the zig zag
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.length();
        if(n == 1 || numRows == 1)
            return s;
        string ans = "";
        vector<vector<string>> grid(numRows, vector<string>(n, "0"));
        int j = 0, l = 0;
        while (l < n)
        {
            int i = 0, k = numRows - 2;
            while(i < numRows && l < n)
            {
                grid[i][j] = s[l];
                l++;
                i++;
            }
            while(k > 0 && l < n)
            {
                j++;
                grid[k][j] = s[l];
                l++;
                k--;
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


// Solution 2.
// O(n) time complexity
// Author: github.com/lzl124631x
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(n == 1 || numRows == 1)
            return s;
        int diff = (numRows - 1)*2;
        string ans = "";
        for(int i = 0; i < numRows; i++)
        {
            int w = 2 * i;
            for(int j = i; j < n;)
            {
                ans += s[j];
                w = diff - w;
                if(!w)
                    w = diff;
                j += w;
            }
        }
        return ans;
    }
};
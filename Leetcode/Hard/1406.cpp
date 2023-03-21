#include "../../headers.h"

class Solution
{
    string rec(vector<int> &v, int a, int b, int t, int i)
    {
        if (i == v.size())
            return a > b ? "Alice" : (a < b ? "Bob" : "Tie");

        string ans = "";
        for (int j = i, sum = 0; j < v.size() && j < i + 3; j++)
        {
            sum += v[j];
            if (!t)
                ans = ans == "Alice" ? ans : rec(v, a + sum, b, t ^ 1, j + 1);
            else
                ans = ans == "Alice" ? ans : rec(v, a, b + sum, t ^ 1, j + 1);
        }
        return ans;
    }

public:
    string stoneGameIII(vector<int> &v)
    {
        return rec(v, 0, 0, 0, 0);
    }
};